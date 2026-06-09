没用哈希表和map,就暴力做了
```
class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean flag=true;
        char tmp;
        int tmpx,tmpy;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    tmp=board[i][j];
                    //处理列和行  这里感觉只要判断它后面有没有即可... 如果前面有是不可能的, 他肯定已经被打掉了
                    for(int ii=i+1;ii<9;ii++){ if(board[ii][j]==tmp)return false;}
                    for(int jj=j+1;jj<9;jj++){ if(board[i][jj]==tmp)return false;}
                    tmpx=((i+3)/3)*3;//去掉余数得到整数  3  6  9
                    tmpy=((j+3)/3)*3;
                    //处理盒子 这里本来想简化 复又想到似乎不能确保在哪 若在中间 就亏了 
                    for(int iii=tmpx-3;iii<tmpx;iii++){
                        for(int jjj=tmpy-3;jjj<tmpy;jjj++){
                            if((iii==i)&&(jjj==j))continue;
                            if(board[iii][jjj]==board[iii][jjj])return false;
                        }
                    }
                }
            }
        }
        return true;
    }
}
```