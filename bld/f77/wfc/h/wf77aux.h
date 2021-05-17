/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2002-2021 The Open Watcom Contributors. All Rights Reserved.
*    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
*
*  ========================================================================
*
*    This file contains Original Code and/or Modifications of Original
*    Code as defined in and that are subject to the Sybase Open Watcom
*    Public License version 1.0 (the 'License'). You may not use this file
*    except in compliance with the License. BY USING THIS FILE YOU AGREE TO
*    ALL TERMS AND CONDITIONS OF THE LICENSE. A copy of the License is
*    provided with the Original Code and Modifications, and is also
*    available at www.sybase.com/developer/opensource.
*
*    The Original Code and all software distributed under the License are
*    distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
*    EXPRESS OR IMPLIED, AND SYBASE AND ALL CONTRIBUTORS HEREBY DISCLAIM
*    ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF
*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR
*    NON-INFRINGEMENT. Please see the License for the specific language
*    governing rights and limitations under the License.
*
*  ========================================================================
*
* Description:  Auxiliary information processing.
*
****************************************************************************/


#include <time.h>


#if _CPU == 386
#define ARG_NEAR            ARG_SIZE_4
#define ARG_FAR             ARG_SIZE_8
#else
#define ARG_NEAR            ARG_SIZE_2
#define ARG_FAR             ARG_SIZE_4
#endif

typedef struct default_lib {
    struct default_lib  *link;
    char                lib[2]; // 1 for priority and 1 for NULLCHAR
} default_lib;

typedef struct arr_info {
    struct arr_info     *link;
    size_t              len;
    char                arr[1];
} arr_info;

typedef struct dep_info {
    struct dep_info     *link;
    time_t              time_stamp;
    char                fn[1];
} dep_info;

extern default_lib      *DefaultLibs;
extern dep_info         *DependencyInfo;

extern void             InitAuxInfo( void );
extern void             FiniAuxInfo( void );
extern void             SubAuxInit( void );
extern void             SubAuxFini( void );
extern void             AddDependencyInfo( source_t *fi );
extern void             DefaultLibInfo( void );
extern void             DoPragma( const char *ptr );
extern void             ProcPragma( const char *ptr );
