;北北北北北北北北北北北北北北北北 ADATA.INC 北北北北北北北北北北北北北�

global newdata1:word

global projxmul:dword
global projymul:dword
global projxadd:word
global projyadd:word
global projminz:dword
global projminzshr:word
global wminx:word
global wminy:word
global wmaxx:word
global wmaxy:word
global vram:word
global rowsadd:word
global truerowsadd:word
global truevram:word
global rows:word
global framerate10:word
global color:word
global color1:byte
global color2:byte
global video:dword
global borders:word

global xadd:dword
global yadd:dword
global zadd:dword

;北北北北北北北北北北北北北北北北 AOBJ.INC 北北北北北北北北北北北北北�

vobj	struc
	xyz	dd 3 dup(0)
	matrix	dw 9 dup(0)
	element	dd 0
vobj	ends

;北北北北北北北北北北北北北北北北 CINK.INC 北北北北北北北北北北北北北�

INT3	MACRO
	int	3
	ENDM

LOADDS 	MACRO
	mov	ax,SEG rows
	mov	ds,ax
	ENDM

LOADGS 	MACRO
	mov	ax,SEG rows
	mov	gs,ax
	ENDM

movpar	MACRO	reg,par ;loads parameter [par(0..)] to register [reg]
	mov	reg,word ptr [bp+par*2+6]
	ENDM

CBEG	MACRO ;C/Assembler procedure begin
	push	bp
	mov	bp,sp
	push	si
	push	di
	push	ds
	ENDM

CEND	MACRO ;C/Assembler procedure end
	pop	ds
	pop	di
	pop	si
	pop	bp
	ret
	ENDM

setborder MACRO col
	mov	al,col
	push	ax
	call	_setborder
	add	sp,2
	ENDM

LOCALS

;VID.ASM
global setvmode:far
global _setborder:far
VIDINIT	equ ds:video[0]
VIDSWITCH equ ds:video[4]
VIDCLEAR64 equ ds:video[8]
VIDPSET equ ds:video[12]
VIDLINE equ ds:video[16]
VIDHLINE equ ds:video[20]
VIDHGROUP equ ds:video[24]
VIDTHGROUP equ ds:video[28]
VIDPOLYGROUP equ ds:video[32]
VIDCLEAR equ ds:video[36]
VIDWAITB equ ds:video[40]
VIDNEWPOLYGROUP equ ds:video[44]
