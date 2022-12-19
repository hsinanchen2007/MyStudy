### 解题思路
创建一个新矩阵，更新下一个状态后后赋值给board

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size()==0)return;
        vector<vector<int>> ans=board;
        int b[8]={-1,0,1,-1,1,-1,0,1};
        int a[8]={-1,-1,-1,0,0,1,1,1};
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                int temp=0;
                for(int k=0;k<8;k++)
                {
                    if(i+a[k]>-1&&i+a[k]<board.size()&&j+b[k]>-1&&j+b[k]<board[0].size())temp+=board[i+a[k]][j+b[k]];
                }
                if(temp==3)ans[i][j]=1;
                else if(temp==2&&board[i][j]==1)ans[i][j]=1;
                else ans[i][j]=0;

            }
        }
        board=ans;

    }
};
```