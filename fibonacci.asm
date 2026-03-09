section .text
global fibonacci
; ecx: unsigned <- index
; rax: unsigned <- return value

fibonacci:
	xor rax, rax
	mov r8, 1

	test ecx, ecx
	jz .end

	cmp ecx, 1
	je .one

	mov r10d, ecx
.loop:
	mov r9, rax
	add rax, r8
	mov r8, r9

	dec r10d
	jnz .loop
.end:
	ret
.one:
	mov rax, r8
	ret
