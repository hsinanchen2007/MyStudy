### 解题思路
先遍历，找到车的位置后break；
分别向四个方向探索：1.找到象，break；2.找到车，加加，break；3.啥也没找，继续找；

### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int i=0,j=0,ii,flag,sum;
    sum=0;flag=0;
    for(i=0;i<boardSize;i++){
        for(j=0;j<boardColSize[i];j++)
            if(board[i][j]=='R') {flag=1 ;break;}
        if(flag) break;
    }
    for(ii=i;ii<boardSize;ii++){
        if(board[ii][j]=='p'){
            sum++;break;
        }
        else if(board[ii][j]=='B'){
            break;
        }
        else;
    }
    for(ii=i;ii>=0;ii--){
        if(board[ii][j]=='p'){
            sum++;break;
        }
        else if(board[ii][j]=='B'){
            break;
        }
        else;
    }
    for(ii=j;ii<boardColSize[i];ii++){
        if(board[i][ii]=='p'){
            sum++;break;
        }
        else if(board[i][ii]=='B'){
            break;
        }
        else;
    }
    for(ii=j;ii>=0;ii--){
        if(board[i][ii]=='p'){
            sum++;break;
        }
        else if(board[i][ii]=='B'){
            break;
        }
        else;
    }
    return sum;
}
```