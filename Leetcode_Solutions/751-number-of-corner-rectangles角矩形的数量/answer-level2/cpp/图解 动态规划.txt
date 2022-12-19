### 解题思路：
**分析**：
- **DP数组**：存储两列之间矩形角点信息，由每行数据更新；
- 利用**grid数组**的每一行更新**DP数组**，在更新**DP数组**之前，更新角矩形总数。

**初始化**：
- **DP数组**元素全部初始化为0。

**结束条件**：
- 遍历达到**grid数组**的最后一行。

### 图解：
<![leetcode750.001.jpeg](https://pic.leetcode-cn.com/6ae605b90475293f361879a0d4590c8e9cf9eb0251ca6c0d4c9b98a74ac6080f-leetcode750.001.jpeg),![leetcode750.002.jpeg](https://pic.leetcode-cn.com/26d5c7164f7f5127e51104dbad5680e796540fda34dc85f03417ae67a5e3014d-leetcode750.002.jpeg),![leetcode750.003.jpeg](https://pic.leetcode-cn.com/9a78d11159a6c1624676d0a5c0cb72113798089b8e1a0c8dcb4c0f3d12277bed-leetcode750.003.jpeg),![leetcode750.004.jpeg](https://pic.leetcode-cn.com/26c52af1e0ef4d1c14e713d2b08d062796b16e255f7c49fe85af8f06d3c9754e-leetcode750.004.jpeg),![leetcode750.005.jpeg](https://pic.leetcode-cn.com/20618a38c75696028af470e8f4a2eba96c97bdb86518f514b6bddb84fb25c381-leetcode750.005.jpeg),![leetcode750.006.jpeg](https://pic.leetcode-cn.com/98b1f9a680eda75fa78b6f70b7c1a97418af6192ae3461a34b9a4586cecc5860-leetcode750.006.jpeg),![leetcode750.007.jpeg](https://pic.leetcode-cn.com/5bae21eff215be4fba705bd039fab77fcbf908e01eb37c4232c691fcd263a81b-leetcode750.007.jpeg),![leetcode750.008.jpeg](https://pic.leetcode-cn.com/4d0fe002e6aacc3f9ddf05c4063a974a19c506a5899a292047a1e8f04193d8ae-leetcode750.008.jpeg),![leetcode750.009.jpeg](https://pic.leetcode-cn.com/6c36b781c4a51c61c5e1db04c015394091fe604cac601ddbc9f5ad2bdb0a4444-leetcode750.009.jpeg),![leetcode750.010.jpeg](https://pic.leetcode-cn.com/3ccc747181863629b9988012115154c034ec2d8586780430ab476aee48e6568a-leetcode750.010.jpeg),![leetcode750.011.jpeg](https://pic.leetcode-cn.com/c199abd3c7d3448c95e39d83fcdb253e9adc85e1df4950a61ae0bb26be22616b-leetcode750.011.jpeg)>

### 代码
```cpp 
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows == 0) {
            return 0;
        }
        int cols = grid[0].size();
        
        int res = 0;
        vector<int> elem = vector<int>(cols, 0);
        vector<vector<int> > dp = vector<vector<int> >(cols, elem);
        for(int r = 0; r < rows; r++) {
            for(int c1 = 0; c1 < cols - 1; c1 ++) {
                if(grid[r][c1] == 1) {
                    for(int c2 = c1 + 1; c2 < cols; c2++) {
                        if(grid[r][c2] == 1) {
                            res += dp[c1][c2];
                            dp[c1][c2] ++;
                        }
                    }
                }
            }
        }
        
        return res;
    }
};
```
