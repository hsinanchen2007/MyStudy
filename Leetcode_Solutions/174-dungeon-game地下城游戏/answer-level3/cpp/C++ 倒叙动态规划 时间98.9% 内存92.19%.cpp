### 解题思路
倒着来的动态规划 基本动态规划思想
因为本题是起始点的数是未知的，而末尾点的数已知

### 代码

```cpp
/*
倒着来的动态规划 基本动态规划思想
因为本题是起始点的数是未知的，而末尾点的数已知
*/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                //分四种情况讨论
                if(i==m-1 && j==n-1){   //终点 即 公主房间
                    dp[i][j] = std::max(1, 1-dungeon[i][j]);     //骑士最少保证有一点生命，1减 是因为保证其生命值为正数，当公主房间为负
                }
                else if(i==m-1){        //最后一行
                    dp[i][j] = std::max(1, dp[i][j+1]-dungeon[i][j]);   //同样要保证每两列值差为正数
                }
                else if(j==n-1){        //最后一列
                    dp[i][j] = std::max(1, dp[i+1][j]-dungeon[i][j]);
                }
                else{                   //其余情况
                    dp[i][j] = std::max(1, std::min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]);     //取右边下边的最小值
                }
            }
        }
        return dp[0][0];
    }
};
```
![TIM图片20191217101126.png](https://pic.leetcode-cn.com/43d263832b2c2836e950bb30dc42ae6d1833409f43a7d662138b7b20841e9d4e-TIM%E5%9B%BE%E7%89%8720191217101126.png)
