includelib legacy_stdio_definitions.lib
extrn printf : near
extrn scanf : near


;; Data segment
.data

; Print statements in the scanf function

print_enter_integer BYTE "Please enter an Integer: ", 0
print_final_statement BYTE "The sum of the max value and user input (%lld, %lld) : %lld", 0Ah, 00h ;max_value, inp_int, sum

; Variables that are used within the scanf function to preserve the input value

public inp_int
inp_int QWORD 0

wtype	db  "%d",0


;; Code segment
.code

;// Finds the max element in the array
public findMax

findMax:	
		mov rax, [rdx]			; moves first element of the array into rax

uppa:	add rdx, 8				; goes to next element in the array
		cmp rax, [rdx]			; compare value and next value
		jle l15					; if rax is smaller, jump to l15

back:	sub rcx, 1				; reduce array size counter
		cmp rcx, 1				; see if its 1
		je finish				; if it is, can return rax
		jmp uppa

l15:	mov rax, [rdx]			; swap the value in the array into rax
		jmp back				; repeat the loop
	
finish:	
		ret
	


public use_scanf
use_scanf:
		
	sub rsp, 40						; creates the shadow space

	call findMax					; calls the findMax function to get max value in the array
	mov [rsp+48], rax				; store this max value in shadow space
	

	lea rcx, print_enter_integer	; load the print statement into rcx
	call printf						; Call the print function printing the statement

	lea  rcx, [wtype]				; Put the message type in rcx
	lea  rdx, [inp_int]				; put the variable where it will be stored in rdx 
	mov al, 0						; The number of arguments in SSE
    call scanf						; Call the scanf function

	mov rbx, [inp_int]				; put the value of the input into rbx
	mov rax, [rsp+48]				; load the saved max value into rax
	add rax, rbx					; get the sum and store in rax
	mov [rsp + 56], rax				; store the sum in the shadow space


	mov r9, rax						; put the sum as the 4th parameter
	mov r8, rbx						; Put the value of the input as the 3rd parameter
	mov rdx, [rsp+48]				; Put the value of the max value as the second parameter
	lea rcx, print_final_statement	; The print statement itself is the first parameter
	call printf						; Call the printf function



	add rsp, 40						; Delete the shadow space

	mov rax, [rsp + 16]				; restore the value of the sum into rax


	ret 


public min5
min5:

	mov [rsp+16], r8			; store the value of k
	mov [rsp+8], r9				; store the value of l

	mov r8, rdx					; put the value j into r8
	mov rdx, rcx				; put the value i into rdx
	mov rcx, inp_int			; put the user input into rcx
	call min					; find the min of these three first

	mov rcx, rax				; put the answer of that min into rcx
	mov rdx, [rsp+16]			; restore value of k
	mov r8, [rsp+8]				; restore value of l
	call min					; find the min of all five

	ret





public min
min:
	mov rax, rcx				; put first parameter into rax
	cmp rax, rdx			
	jg l10						; if first is less than second

afirst: cmp rax, r8				
	jg l11						; if rax is smaller than the third parameter

	jmp toEnd

l10: mov rax, rdx				; make rax the value of the second parameter
	jmp afirst


l11: mov rax, r8				; make rax the third parameter
	
toEnd:	
	ret 0




public gcd_recursion

gcd_recursion :

  cmp rdx, 0			; compare a%b = 0
  je theE


  mov rax, rcx			; Puts a into rax
  mov rcx, rdx			; Puts b into a slot
  xor rdx, rdx
  idiv rcx				; divides a/b
  call gcd_recursion

theE:
	mov rax, rcx		; Put the b value into rax
	ret 


end