int findDw(int dwRow, int dwCol, char** board, int row, int col, char* word, int wordLen){

    if(wordLen == 0){
        return true;
    }
    char dw = word[strlen(word) - wordLen];

    //printf("%d %d %c %c\r\n",dwRow,dwCol,board[dwRow][dwCol],dw);
    //如果不相等，返回
    if(board[dwRow][dwCol] != dw){
        return false;
    }
    char temp = board[dwRow][dwCol];
    board[dwRow][dwCol] = '0';
    //up
    if(dwRow > 0){
        if(findDw(dwRow-1,dwCol,board,row,col,word,wordLen-1)){
            return true;
        }
        //board[dwRow][dwCol] = temp;
    }
    //down
    if(dwRow + 1 < row){
        if(findDw(dwRow+1,dwCol,board,row,col,word,wordLen-1)){
            return true;
        }
        //board[dwRow][dwCol] = temp;
    }
    //left
    if(dwCol > 0){
        if(findDw(dwRow,dwCol - 1,board,row,col,word,wordLen-1)){
            return true;
        }
        //board[dwRow][dwCol] = temp;
    }
    //right
    if(dwCol + 1 < col){
        if(findDw(dwRow,dwCol + 1,board,row,col,word,wordLen-1)){
            return true;
        }
        //board[dwRow][dwCol] = temp;
    }
    board[dwRow][dwCol] = temp;
    return false;

}

bool exist(char** board, int boardSize, int* boardColSize, char * word){

    //遍历第一个字母的位置
    int row = boardSize;
    int col = * boardColSize;
    int i = 0;
    int j = 0;

    //printf("%d %d \r\n",row,col);

    //递归的找上下左右,找不下去时,回退上一层继续找
    for(i = 0; i< row; i++){
        for(j = 0; j < col; j++){
            if(board[i][j] == word[0]){
                if(strlen(word) == 1){
                    return true;
                }
                if(findDw(i,j,board,row,col,word,strlen(word))){
                    return true;
                }
            }
        }
    }

    //printf("%d %d %c\r\n",boardSize,* boardColSize,word[0]);

    return false;

}

