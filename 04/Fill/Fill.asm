(LOOP)
    @i
    M=0

    @KBD
    D=M         

    @KEY_PRESSED
    D;JGT  

    @NO_KEY
    0;JMP

(KEY_PRESSED)
    @16383
    M=0
    @i
    M=M+1
    D=M
    @16383
    A=D+A
    M=-1

    @KBD
    D=M
    @KEY_PRESSED
    D;JGT

(NO_KEY)
    @16383
    M=0
    @i
    M=M+1
    D=M
    @16383
    A=D+A
    M=0
    @KBD
    D=M
    @KEY_PRESSED
    D;JGT

    @KBD
    D=M
    @NO_KEY
    0;JMP


(END)
    @LOOP
    0;JMP