#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/cred.h>
#include <linux/security.h>
#include <linux/string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 32
#define MAX_PASSWORD_LENGTH 64

struct evo_user {
    char username[MAX_USERNAME_LENGTH];
    char password_hash[MAX_PASSWORD_LENGTH];
    uid_t uid;
    gid_t gid;
};

static struct evo_user users[MAX_USERS];
static int num_users = 0;

// Simple string hash function (placeholder - replace with secure hash in production)
static u32 simple_str_hash(const char *str) {
    u32 hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;

    return hash;
}

// Lookup a user
static struct evo_user *evo_lookup_user(const char *username)
{
    int i;
    for (i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return &users[i];
        }
    }
    return NULL;
}

// Create a new user
static int evo_create_user(const char *username, const char *password, uid_t uid, gid_t gid)
{
    if (num_users >= MAX_USERS) {
        return -ENOSPC;
    }

    if (evo_lookup_user(username) != NULL) {
        return -EEXIST;
    }

    struct evo_user *new_user = &users[num_users];
    strncpy(new_user->username, username, MAX_USERNAME_LENGTH - 1);
    new_user->username[MAX_USERNAME_LENGTH - 1] = '\0';

    u32 hash = simple_str_hash(password);
    snprintf(new_user->password_hash, MAX_PASSWORD_LENGTH, "%u", hash);

    new_user->uid = uid;
    new_user->gid = gid;

    num_users++;
    printk(KERN_INFO "EvoOS: Created user %s\n", username);
    return 0;
}

// Function to create test users
static void create_test_users(void)
{
    evo_create_user("root", "rootpassword", 0, 0);
    evo_create_user("user1", "user1password", 1000, 1000);
    evo_create_user("user2", "user2password", 1001, 1001);
}

// Authenticate a user
static int evo_authenticate_user(const char *username, const char *password)
{
    struct evo_user *user = evo_lookup_user(username);
    if (user == NULL) {
        return -ENOENT;
    }

    u32 hash = simple_str_hash(password);
    char hash_str[MAX_PASSWORD_LENGTH];
    snprintf(hash_str, MAX_PASSWORD_LENGTH, "%u", hash);

    if (strcmp(user->password_hash, hash_str) == 0) {
        printk(KERN_INFO "EvoOS: Authenticated user %s\n", username);
        return 0;
    }

    return -EACCES;
}

// Delete a user
static int evo_delete_user(const char *username) {
    int i;
    for (i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            if (i < num_users - 1) {
                memmove(&users[i], &users[i+1], sizeof(struct evo_user) * (num_users - i - 1));
            }
            num_users--;
            printk(KERN_INFO "EvoOS: Deleted user %s\n", username);
            return 0;
        }
    }
    return -ENOENT;
}

// Change a user's password
static int evo_change_password(const char *username, const char *new_password) {
    struct evo_user *user = evo_lookup_user(username);
    if (user == NULL) {
        return -ENOENT;
    }

    u32 hash = simple_str_hash(new_password);
    snprintf(user->password_hash, MAX_PASSWORD_LENGTH, "%u", hash);

    printk(KERN_INFO "EvoOS: Changed password for user %s\n", username);
    return 0;
}

// Initialize the user authentication module
static int __init evo_user_auth_init(void)
{
    printk(KERN_INFO "EvoOS: Initializing User Authentication module\n");
    create_test_users();
    return 0;
}

// Cleanup the user authentication module
static void __exit evo_user_auth_exit(void)
{
    printk(KERN_INFO "EvoOS: Exiting User Authentication module\n");
    // Clear user data for security
    memset(users, 0, sizeof(users));
    num_users = 0;
}

module_init(evo_user_auth_init);
module_exit(evo_user_auth_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EvoOS Team");
MODULE_DESCRIPTION("EvoOS User Authentication Module");
