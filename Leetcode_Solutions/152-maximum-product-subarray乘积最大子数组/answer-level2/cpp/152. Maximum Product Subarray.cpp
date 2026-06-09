### 解题思路
DP
注意状态转移方程是否经得起推敲
![a5306c52dbd3e1c17abb18d5cece0a7.jpg](https://pic.leetcode-cn.com/e88e13f8b8396b0df08d24cbba4a2cfb59b78b76100e7a8222c35984657d6713-a5306c52dbd3e1c17abb18d5cece0a7.jpg)

### 代码

```cpp
class Solution {
    //考虑穷举情况下，时间复杂度O(N2),那么动态规划应该会优化到O(N)
    //dp[i] 前i项最大的乘积???
    //dp[i] = (dp[i-1] * nums[i-1] > 0) ? dp[i-1] * nums[i-1] : dp[i-1] ???(错误的状态转移方程)
    //dp[i] 以i结尾的子序列的最大/小的乘积
    //dmax[i] = max(dmax[i-1]*nums[i-1], nums[i-1]);
    //dmin[i] = min(dmin[i-1]*nums[i-1], nums[i-1]);
public:
    int maxProduct(vector<int>& nums) {
        int dmax[nums.size() + 1] = {0};
        int dmin[nums.size() + 1] = {0};
        dmax[0] = 1;
        dmin[0] = 1;
        int ret = 0x80000000;
        for(int i = 1; i <= nums.size(); i++){
            if(nums[i - 1] < 0){
                int temp = dmax[i-1];
                dmax[i-1] = dmin[i-1];
                dmin[i-1] = temp;
            }
            dmax[i] = max(dmax[i-1]*nums[i-1], nums[i-1]);
            dmin[i] = min(dmin[i-1]*nums[i-1], nums[i-1]);
            ret = max(ret, dmax[i]);
        }              
        return ret;
    }
};
```