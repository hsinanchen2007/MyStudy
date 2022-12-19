### 解题思路
遍历法找到车，然后前后左右四个b方向逐个寻找兵，找到兵或找到象或到达边缘则结束。

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans=0;
        int find=0;
        int ri=0;
        int rj=0;
        for(int i=0;i<board.size()&&find==0;i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='R')
                {
                    ri=i;
                    rj=j;
                    find=1;
                    break;
                }
            }
        }
        int i=1;
        while(ri>=i&&board[ri-i][rj]!='B')
        {
            if(board[ri-i][rj]=='p')
            {
                ans++;
                break;
            }
            i++;
        }
        i=1;
        while(ri+i<board.size()&&board[ri+i][rj]!='B')
        {
            if(board[ri+i][rj]=='p')
            {
                ans++;
                break;
            }
            i++;
        }

        i=1;
        while(rj>=i&&board[ri][rj-i]!='B')
        {
            if(board[ri][rj-i]=='p')
            {
                ans++;
                break;
            }
            i++;
        }
        i=1;
        while(rj+i<board[0].size()&&board[ri][rj+i]!='B')
        {
            if(board[ri][rj+i]=='p')
            {
                ans++;
                break;
            }
            i++;
        }
        return ans;
    }
};
```