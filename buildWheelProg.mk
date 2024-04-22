# Directories

HDR='.\\include'
OBJ='.\\obj'
SRC='.\\src'
EXE='.\\exe'

# Compiler

CC='gcc'

# Flags

chkFlgs='-Wall -Werror'
hdrFlg="-I$(HDR)"

#____________________Rules_______________


# objs rule (Object file storage problem solution remaining)

$(OBJ)\\%.o: $(SRC)\\%.c $(HDR)\\*.h
	$(CC) $(chkFlg) -c $< -o $(OBJ)\\ $(hdrFlg)



# exe file compilation rule

$(EXE)\\bicycleWheelProblem: $(OBJ)\\*.o
	$(CC) $(chkFlg) $^ -o $@ $(hdrFlg)
