/*
 *   File:       cexception.h
 *
 *   Contains:   cexception macros
 *
 *   Written by: GuEe-GUI
 *
 *   Copyright:  (C) 2017-2022 by GuEe Studio. All rights reserved.
 *
 *   License:    Apache-2.0
 */

#ifndef __CEXCEPTION_H__
#define __CEXCEPTION_H__

#ifdef __cplusplus
#error Fuck, do not include it in c++ source!
#endif

#if defined(try) || defined(catch) || defined(throw)
#error Do not define try, catch, or throw by yourself!
#endif

#include <setjmp.h>

void cexception_jmp_stack_push(jmp_buf* jb);
jmp_buf* cexception_jmp_stack_pop();

#define try                                     \
    jmp_buf __jmp_buf;                          \
    int __jmp_result = setjmp(__jmp_buf);       \
    if (!__jmp_result)                          \
    {                                           \
        cexception_jmp_stack_push(&__jmp_buf);  \
    }                                           \
    if (!__jmp_result)

#define catch(x)                    \
    int x = __jmp_result;           \
    if (!x)                         \
    {                               \
        cexception_jmp_stack_pop(); \
    }                               \
    else

#define throw(x) longjmp(*cexception_jmp_stack_pop(), x);

#endif /* __CEXCEPTION_H__ */
