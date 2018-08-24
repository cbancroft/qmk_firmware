SRC += cbancroft.c

ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
  SRC += secrets.c
endif

EXTRAFLAGS        += -flto 		# Used to make code smaller

ifeq ($(strip $(NO_SECRETS)), yes)
    OPT_DEFS += -DNO_SECRETS
endif

ifeq ($(strip $(MACROS_ENABLED)), yes)
    OPT_DEFS += -DMACROS_ENABLED
endif

ifdef CONSOLE_ENABLE
  ifeq ($(strip $(KEYLOGGER_ENABLE)), yes)
    OPT_DEFS += -DKEYLOGGER_ENABLE
  endif
endif
