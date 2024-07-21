# Makefile for EvoOS Kernel

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -O2 -I/usr/src/linux-headers-6.2.0-1018-aws/include -I/usr/src/linux-headers-6.2.0-1018-aws/arch/x86/include/generated -I/usr/src/linux-headers-6.2.0-1018-aws/arch/x86/include

# Directories
SRCDIR := src
INCDIR := include
OBJDIR := obj
SECDIR := security

# Source files
CORE_SRC := $(wildcard $(SRCDIR)/core/*.c)
FS_SRC := $(wildcard $(SRCDIR)/fs/*.c)
MM_SRC := $(wildcard $(SRCDIR)/mm/*.c)
PM_SRC := $(wildcard $(SRCDIR)/pm/*.c)
DD_SRC := $(wildcard $(SRCDIR)/drivers/*.c)
SEC_SRC := $(wildcard $(SECDIR)/*/*.c)
UI_SRC := $(wildcard $(SRCDIR)/ui/*.c)

# Object files
CORE_OBJ := $(patsubst $(SRCDIR)/core/%.c,$(OBJDIR)/core/%.o,$(CORE_SRC))
FS_OBJ := $(patsubst $(SRCDIR)/fs/%.c,$(OBJDIR)/fs/%.o,$(FS_SRC))
MM_OBJ := $(patsubst $(SRCDIR)/mm/%.c,$(OBJDIR)/mm/%.o,$(MM_SRC))
PM_OBJ := $(patsubst $(SRCDIR)/pm/%.c,$(OBJDIR)/pm/%.o,$(PM_SRC))
DD_OBJ := $(patsubst $(SRCDIR)/drivers/%.c,$(OBJDIR)/drivers/%.o,$(DD_SRC))
SEC_OBJ := $(patsubst $(SECDIR)/%.c,$(OBJDIR)/security/%.o,$(SEC_SRC))
UI_OBJ := $(patsubst $(SRCDIR)/ui/%.c,$(OBJDIR)/ui/%.o,$(UI_SRC))

# All object files
OBJ := $(CORE_OBJ) $(FS_OBJ) $(MM_OBJ) $(PM_OBJ) $(DD_OBJ) $(SEC_OBJ) $(UI_OBJ)

# Kernel image
KERNEL := evoos_kernel

# Phony targets
.PHONY: all clean

# Default target
all: $(KERNEL)

# Kernel image
$(KERNEL): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Object files
$(OBJDIR)/core/%.o: $(SRCDIR)/core/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCDIR) -c -o $@ $<

$(OBJDIR)/fs/%.o: $(SRCDIR)/fs/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCDIR) -c -o $@ $<

$(OBJDIR)/mm/%.o: $(SRCDIR)/mm/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCDIR) -c -o $@ $<

$(OBJDIR)/pm/%.o: $(SRCDIR)/pm/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCDIR) -c -o $@ $<

$(OBJDIR)/drivers/%.o: $(SRCDIR)/drivers/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCDIR) -c -o $@ $<

$(OBJDIR)/security/%.o: $(SECDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCDIR) -c -o $@ $<

$(OBJDIR)/ui/%.o: $(SRCDIR)/ui/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCDIR) -c -o $@ $<

# Clean
clean:
	rm -rf $(OBJDIR) $(KERNEL)
