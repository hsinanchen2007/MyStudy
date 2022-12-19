我看了一些其他大佬的解法，对于C语言来说是没有什么好的办法，就是一个个的验证。

大家可以稍微学习一下我的方向数组的用法，其他的就是死磕了。
```
bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int mark1[9];//行
    int mark2[9];
    int i,j;

    //验证行和列
    for(i=0;i<9;i++)
    {
        memset(mark1,0,sizeof(int)*9);//行初始化
        memset(mark2,0,sizeof(int)*9);//列初始化
        for(j=0;j<9;j++)
        {
            if(board[i][j]!='.')
            mark1[board[i][j]-'1']++;
            if(board[j][i]!='.')
            mark2[board[j][i]-'1']++;
        }
        for(j=0;j<9;j++)
        if(mark1[j]>1||mark2[j]>1)
            return false;
    }

    int dir1[9]={-1,-1,-1,0,0,0,1,1,1};//方向数组
    int dir2[9]={-1,0,1,-1,0,1,-1,0,1};
    int new_x,new_y;
    int k;

    for(i=1;i<9;i+=3)//行跳
        {
            for(j=1;j<9;j+=3)//列跳
            {
                memset(mark1,0,sizeof(int)*9);//初始化
                for(k=0;k<9;k++)
                {
                    new_x=i+dir1[k];
                    new_y=j+dir2[k];
                    if(board[new_x][new_y]=='.') continue;
                    int num=board[new_x][new_y]-'1';
                    if(mark1[num]>0)
                    return false;
                    else
                    mark1[num]=1;
                }
            }
        }
    return true;
        

}
```
