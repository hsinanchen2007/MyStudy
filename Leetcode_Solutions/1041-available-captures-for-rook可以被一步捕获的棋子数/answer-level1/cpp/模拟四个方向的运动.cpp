```
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x,y;
        int count=0;
        int lx[4]={0,1,0,-1};
        int ly[4]={1,0,-1,0};

        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                if(board[i][j]=='R')
                {
                    x=i;
                    y=j;
                    break;
                }
        for(int k=0;k<4;k++)
        {
                for(int m=x,n=y;m<8&&m>=0&&n>=0&&n<8;)
                {
                        m+=lx[k];
                        n+=ly[k];
                    if(m>=8||m<0||n>=8||n<0||board[m][n]=='B')
                        break;
                    if(board[m][n]=='p')
                    {
                         count++;
                         break;
                    } 
                }
        }
        return count;
    }
};
```
