### 解题思路
直接条件一个个列出来判断，注意赋值出来一个数组即可。不过这都能双百也是惊了。

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp(board);
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0; j<n; j++){
                int count = 0;
                if(i>0 && temp[i-1][j]==1)
                    count++;
                if(i>0 && j>0 && temp[i-1][j-1]==1)
                    count++;
                if(i>0 && j<n-1 && temp[i-1][j+1]==1)
                    count++;
                if(j>0 && temp[i][j-1]==1)
                    count++;
                if(j<n-1 && temp[i][j+1]==1)
                    count++;
                if(i<m-1 && temp[i+1][j]==1)
                    count++;
                if(i<m-1 && j>0 && temp[i+1][j-1]==1)
                    count++;
                if(i<m-1 && j<n-1 && temp[i+1][j+1]==1)
                    count++;
                if(temp[i][j]==1){
                    if(count<2 || count>3)
                        board[i][j] = 0;
                    else
                        board[i][j] = 1;
                }
                else{
                    if(count==3)
                        board[i][j] = 1;
                    else
                        board[i][j] = 0;
                }
            }
        }
    }
};
```

![image.png](https://pic.leetcode-cn.com/a4ff7aceaee2ad0da82c193828173b2c35c8b07d63c03e7a571b88f331025280-image.png)
