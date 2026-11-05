	@R2
	M=0
	// clear memory 
	@R0
	D=M
	// take input value 1 and set it to -i so we can count to 0 for the flag 
	@i
	M=-D

(LOOP)
	// take I in memory value save to D
	@i
	D=M
	@STOP
	// If 0 stop flag 
	D;JEQ
	// Grab input value 2 from R1 put into D 
	@R1
	D=M
	// R2 is the sum value take R1 D add Current Sum to that and store back in D
	@R2
	D=D+M
	@R2
	M=D
	// Save D back into R2 memory slot
	// i = i + 1
	@i
	M=M+1
	// check if break otherwise jump back up 
	@LOOP
	0;JMP
(STOP)

(END)
	@END
	0;JMP