### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public: 
    int numRookCaptures(vector<vector<char>>& board)
    {
        int res=0;
        int starti=-1;
        int startj=-1;
        vector<vector<bool>>visited(8,vector<bool>(8,false));
        for(int i=0;i<8&&starti==-1&&startj==-1;i++)
        {
            for(int j=0;j<8&&starti==-1&&startj==-1;j++)
            {
                if(board[i][j]=='R')
                {
                    starti=i;
                    startj=j;
                }
            }
        }
        vector<int>x={-1,1,0,0};
        vector<int>y={0,0,-1,1};
        for(int k=0;k<4;k++)
        {
            int curx=starti;
            int cury=startj;
            while(curx>=0&&curx<8&&cury>=0&&cury<8&&board[curx][cury]!='B')
            {
                if(board[curx][cury]=='p')
                {
                    res++;
                    break;
                }
                curx=x[k]+curx;
                cury=y[k]+cury;
            }

        }
        return res;
    }
};
```