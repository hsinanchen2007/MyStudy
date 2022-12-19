### 解题思路
这题目描述真是让人费解。。。

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans=0;
        for(int i=0;i<8;++i)
        {
            for(int j=0;j<8;++j)
            {
                if(board[i][j]=='R')
                {
                    //向上
                    int up=i-1;
                    while(up>=0)
                    {
                        if(board[up][j]=='p')
                        {
                            ans++;
                            break;
                        }
                        if(board[up][j]=='B') break;
                        --up;
                    }
                    //向下
                    int down=i+1;
                    while(down<8)
                    {
                        if(board[down][j]=='p')
                        {
                            ans++;
                            break;
                        }
                        if(board[down][j]=='B') break;
                        ++down;
                    }
                    //向左
                    int left=j-1;
                    while(left>=0)
                    {
                        if(board[i][left]=='p')
                        {
                            ans++;
                            break;
                        }
                        if(board[i][left]=='B') break;
                        --left;
                    }
                    //向右
                    int right=j+1;
                    while(right<8)
                    {
                        if(board[i][right]=='p')
                        {ans++;break;}
                        if(board[i][right]=='B') break;
                        ++right;
                    }
                }
            }
        }
        return ans;
    }
};
```