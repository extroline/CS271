(LOOP)
    @KBD
    D=M         

    @Black
    D;JGT  

(White)
    @color
    M=0
    @SCREEN 
    D=A
    @ADDR 
    M=D

    @DRAW
    D;JMP

(Black)

    @color
    M=-1
    @SCREEN 
    D=A
    @ADDR 
    M=D

    @DRAW
    D;JMP

(DRAW)
    @color 
    D=M 

    @ADDR 
    A=M
    M=D

    @ADDR 
    M=M+1

    @KBD
    D=A 
    @ADDR
    D=D-M

    @DRAW
    D;JGT 

    @LOOP 
    0;JMP