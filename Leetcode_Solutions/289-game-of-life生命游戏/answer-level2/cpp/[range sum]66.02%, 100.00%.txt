### 解题思路
![289_lifeGame_rangeSum.png](https://pic.leetcode-cn.com/c0c8c0333d5f0053e5311839467ace9c4486f218f60e588b0358bdc4571b4265-289_lifeGame_rangeSum.png)
看大家的解法比较集中，更新一个新思路，用range sum，抠掉中心点就可以得到环形面积和了，空间复杂度O(M*N)
通过indice arithmatics，把board面积求和与环形面积求和合并在一起，时间复杂度O(M*N)
请大家指点为什么时间复杂度只跑赢了66.02%， 怎么看都应该比主流解法快才对


### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
    //    border problem fix: 
    //   0 0 0 0
    //   0 0 0 0 
    //   0 0 x---|
    //   0 0 |---|
    //   
            //  S O(MN)
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> sum (m + 3, vector<int>(n + 3, 0));
        for (int i = 2; i < m + 3; ++i){
            for (int j = 2; j < n + 3; ++j){
                sum[i][j] = ((i - 2 == m || j - 2 == n) ? 0 : board[i - 2][j - 2]) + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
                if (i > 2 && j > 2) {
                        int tmp = sum[i][j] - sum[i - 3][j] - sum[i][j - 3] + sum[i - 3][j - 3] - board[i - 3][j - 3];
                    if (tmp == 2 || tmp == 3) {
                        if (tmp == 3) board[i - 3][j - 3] =  1;
                    }
                    else board[i - 3][j - 3] = 0;                    
                }
            }
        }
    }
};
```