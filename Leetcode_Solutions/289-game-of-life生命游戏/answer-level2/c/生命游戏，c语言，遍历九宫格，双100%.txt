### 解题思路
原地算法，所以用二进制的第二位来存放变化后的状态。如果不会位运算就去百度。
学到了遍历九宫格的小技巧。
### 代码

```c
void gameOfLife(int** board, int boardSize, int* boardColSize){
    int neighbors[3] = {-1,0,1};   //遍历九宫格的小技巧
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardColSize[0];j++){
            int neinum=0,row,column;
            for(int x=0;x<3;x++){
                for(int y=0;y<3;y++){
                    if(x!=1 || y!=1){  //不算本身
                        row = i+neighbors[x];
                        column = j+neighbors[y];
                        if((row<boardSize && row>=0) && (column>=0 && column<boardColSize[0]) && (board[row][column]&1==1)){
                            neinum++;
                        }
                    }
                }
            }
            if(board[i][j] == 1){
                if(neinum==2 || neinum==3){   //其他的都死了，二进制第二位是0，不用变
                    board[i][j] += 2;
                }
            }else{
                if(neinum == 3){    //其他还是死。
                    board[i][j] += 2;
                }
            }
        }
    }
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardColSize[0];j++){
            board[i][j] >>= 1;
        }
    }
}
```