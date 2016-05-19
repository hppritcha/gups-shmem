configdir = $(datarootdir)/${PACKAGE_NAME}
AM_CFLAGS = -g -Wall -D_GNU_SOURCE -D 'CONFIG_PATH="${configdir}"'
ACLOCAL_AMFLAGS = -I config

bin_PROGRAMS = \
	gups

gups_SOURCES = \
	src/RandomAccess.c \
	src/driver.c \
	src/starts.c
