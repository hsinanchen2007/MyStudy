
![image.png](https://pic.leetcode-cn.com/8afbb89655e3a3a4e0571cbf1b1ab3b1d8b85a95b41b2f5a250727ea20cf8dee-image.png)

### 解题思路
1.计算棋子数量、和获胜人
2.判断是否合理

### 代码

```c

void whoWin(bool* X,bool* O,char ** board){
    //printf("%d",strcmp(board[0],"XXX") == 0);
    if((strcmp(board[0],"XXX") == 0)||(strcmp(board[1],"XXX") == 0)||(strcmp(board[2],"XXX") == 0)||
       ((board[0][0] == board[1][0])&&(board[0][0] == board[2][0])&&(board[0][0] == 'X'))||
        ((board[0][0] == board[1][1])&&(board[2][2] == board[0][0])&&(board[0][0] == 'X'))||
        ((board[0][2] == board[1][1])&&(board[0][2] == board[2][0])&&(board[0][2] == 'X'))){
            *X = true;
            printf("yes");
        }
    //printf("11");    
    if((strcmp(board[0],"OOO") == 0)||(strcmp(board[1],"OOO") == 0)||(strcmp(board[2],"OOO") == 0)||
       ((board[0][0] == board[1][0])&&(board[0][0] == board[2][0])&&(board[0][0] == 'O'))||
        ((board[0][0] == board[1][1])&&(board[2][2] == board[0][0])&&(board[0][0] == 'O'))||
        ((board[0][2] == board[1][1])&&(board[0][2] == board[2][0])&&(board[0][2] == 'O')))
        *O = true;
}
bool validTicTacToe(char ** board, int boardSize){
int Xn = 0;
int On = 0;
for(int i = 0; i < 3;i++){
    for(int j = 0; j < 3;j++){
        if(board[i][j] == 'O')
            On++;
        if(board[i][j] == 'X')
            Xn++;
    }
}
if(On > Xn||Xn - On > 1)
    return false;
bool Xwin = false;
bool Owin = false;

whoWin(&Xwin,&Owin,board);
printf("%s\n",board[0]);
printf("%d %d",Xwin,Owin);
if(((!Xwin)&&(!Owin)) || (Xwin&&(!Owin)&&((Xn-On) == 1))|| (Owin&&(!Xwin)&&((Xn-On) == 0)))
    return true;
return false;
}
```