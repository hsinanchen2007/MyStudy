### 解题思路
本来用了两层for,可惜时间复杂度高了，考虑去掉一层for
为了使得乘积最大，那么考虑到两种情况：
- 一种是从i_th数开始，前面的乘积中最大 * 当前的正数
- 一种是从i_th数开始，前面的乘积中最小（为负数）*当前的负数
- 考虑到前面一位可能为0，所以代码中要和当前的数进行最大最小比较

### 代码

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //当前结尾的最大值和最小值都要保存下来
        int imax = nums[0];
        int ans = nums[0];
        int imin = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            int t_imax = max(max(imin*nums[i], imax*nums[i]), nums[i]);
            int t_imin = min(min(imin*nums[i], imax*nums[i]), nums[i]);
            //上式中一次循环会改变 imax的值从而影响 imin的计算，所以用临时变量t_imax，t_imin
            imax = t_imax;
            imin = t_imin;
            if(ans < imax)
                ans = imax;
        }
        return ans;
    }
};
```