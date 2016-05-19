dnl
dnl Copyright (c) 2016 Cisco Systems, Inc.  All rights reserved.
dnl
dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.57)
AC_INIT([gups-shmem], [1.0.0], [https://github.com/hppritcha/gups-shmem])
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_MACRO_DIR(config)
AC_CONFIG_HEADERS(config.h)
AM_INIT_AUTOMAKE([1.11 dist-bzip2 foreign -Wall -Werror subdir-objects])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

AC_CANONICAL_HOST

AM_PROG_LIBTOOL

dnl Checks for programs
AC_PROG_CC([oshcc])
AM_PROG_CC_C_O

dnl Checks for header files.
AC_HEADER_STDC

dnl Check for shmem support
AC_MSG_CHECKING(checking for shmem support)
AC_TRY_LINK([#include <shmem.h>],
    [shmem_init();
     shmem_finalize();
    ],
    [AC_MSG_RESULT(yes)],
    [AC_MSG_ERROR([no shmem.h header found. Maybe need to set CC=oshcc?])])

LT_INIT

dnl check for header files
AC_CHECK_HEADER(shmem.h, [],
    AC_MSG_ERROR([no shmem.h header found. Maybe need to set CC=oshcc?]))


AC_CONFIG_FILES([Makefile])
AC_OUTPUT
