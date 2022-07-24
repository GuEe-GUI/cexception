/*
 *   File:       cexception.c
 *
 *   Contains:   cexception process
 *
 *   Written by: GuEe-GUI
 *
 *   Copyright:  (C) 2017-2022 by GuEe Studio. All rights reserved.
 *
 *   License:    Apache-2.0
 */

#include <malloc.h>
#include <assert.h>

#include "cexception.h"

#define MIN_JUMP_STACK 128

static struct
{
    int idx;
    int top;

    jmp_buf **stack;
} _jmp_buf_stack = { 0, MIN_JUMP_STACK, NULL };

void cexception_jmp_stack_push(jmp_buf* jb)
{
    if (_jmp_buf_stack.stack == NULL)
    {
        _jmp_buf_stack.stack = (jmp_buf **)malloc(MIN_JUMP_STACK);

        assert(_jmp_buf_stack.stack != NULL);
    }
    else if (_jmp_buf_stack.idx >= _jmp_buf_stack.top)
    {
        _jmp_buf_stack.top += MIN_JUMP_STACK;

        _jmp_buf_stack.stack = (jmp_buf **)realloc(_jmp_buf_stack.stack, _jmp_buf_stack.top);

        assert(_jmp_buf_stack.stack != NULL);
    }

    _jmp_buf_stack.stack[_jmp_buf_stack.idx++] = jb;
}

jmp_buf* cexception_jmp_stack_pop()
{
    assert(_jmp_buf_stack.stack != NULL);
    assert(_jmp_buf_stack.idx > 0);

    return _jmp_buf_stack.stack[--_jmp_buf_stack.idx];
}
