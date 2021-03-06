/* i386-specific implemetation of profiling support.
   Copyright (C) 1997, 2002 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@cygnus.com>, 1997.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */


/* We need a special version of the `mcount' function since for ix86 it
   must not clobber any register.  This has several reasons:
     - there is a bug in gcc as of version 2.7.2.2 which prohibits the
       use of profiling together with nested functions
     - the ELF `fixup' function uses GCC's regparm feature
     - some (future) systems might want to pass parameters in registers.  */

        .globl _mcount
	.type _mcount,@function;
	.align 1<<4
_mcount:
	/* Save the caller-clobbered registers.  */
	pushl %eax
	pushl %ecx
	pushl %edx

	movl 12(%esp), %edx
	movl 4(%ebp), %eax

	/* No need to access the PLT or GOT, __mcount_internal is an
	   internal function and we can make a relative call.  */
	call __mcount_internal

	/* Pop the saved registers.  Please note that `mcount' has no
	   return value.  */
	popl %edx
	popl %ecx
	popl %eax
	ret
	.size _mcount,.-_mcount;

#undef mcount
.weak mcount ; mcount = _mcount
