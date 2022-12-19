```
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int t1[10],t2[10],t3[10][10]={0},a,b,k;
        for(int i=0;i<9;i++)
        {
            memset(t1,0,sizeof(t1));
            memset(t2,0,sizeof(t2));  //节省空间，重复使用
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.'){
                    
                    //行处理
                    a=board[i][j]-'0';
                    if(t1[a]>0) return false;
                    t1[a]++;
                    
                    //3*3方格处理
                    k=(i/3)*3+j/3;  //将3*3的小方格分别编号为0...8
                    if(t3[k][a]>0) return false;
                    t3[k][a]++;
                }
                if(board[j][i]!='.')  //列处理
                {
                    b=board[j][i]-'0';
                    if(t2[b]>0) return false;
                    t2[b]++;
                }
            }
        }
        return true;
    }
};
```
