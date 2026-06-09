### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
    private:
    int dx[8]={-1,0,1,1,1,0,-1,-1};
    int dy[8]={-1,-1,-1,0,1,1,1,0};
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> ss(board.size()+2, vector<int>(board[0].size()+2, 0));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                ss[i+1][j+1]=board[i][j];
            }
        }
        for(int i=1;i<ss.size()-1;i++)
        {
            for(int j=1;j<ss[0].size()-1;j++)
            {
                int num=0;
                for(int k=0;k<8;k++)
                {
                    if(ss[i+dx[k]][j+dy[k]]==1) num++;
                }
                if(num<2)board[i-1][j-1]=0;
                else if((num==2||num==3)&&ss[i][j]==1)board[i-1][j-1]=1;
                else if(num>3)board[i-1][j-1]=0;
                else if(num==3&&ss[i][j]==0)board[i-1][j-1]=1;
            }
        }
    }
};
```