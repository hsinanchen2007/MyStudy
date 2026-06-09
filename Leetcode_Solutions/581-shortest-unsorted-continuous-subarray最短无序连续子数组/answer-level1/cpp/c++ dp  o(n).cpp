### 解题思路
思路要点：如果一个数字经过排序后在数组中的位置没有改变，必须同时满足两个条件
1. 在之前没有比该数字大的数字
2. 在之后没有比该数字小的数字

因此我们定义一个dp数组，dp[i]=1表示该nums[i]满足比前面数字都大，且比后面数字都小。
我们只需要从前向后迭代一遍就可以判断每个数字是否比前面数字都大，
在从后向前迭代一遍就可以判断每个数字是否比后面数字都小。
然后找到dp[i] = 0的i的最小值min和最大值max， max-min+1就是要求的结果

### 代码

```cpp
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (!nums.size()) return 0;
        vector<bool> dp(nums.size(), 1);               // 初始dp[i]全部置为1
        int maxnum = nums[0];                          
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < maxnum) {                    // 从前向后迭代，前面有大于nums[i]的，dp[i]置0
                dp[i] = 0;
            } else {
                 maxnum = nums[i];                     // 当前数字大于maxnums，更新maxnums
            }
        }
        int minnum = nums[nums.size()-1];
        int min_r = nums.size();
        int max_r = -1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] > minnum) {                    // 从后向前迭代，后面有小于nums[i]的，dp[i]置0
                dp[i] = 0;
            } else {
                minnum = nums[i];                      // 当前数字小于minnums，更新minnums           
            }
            if (!dp[i]) {                              // dp[i]为0时，更新min_r, max_r。
                min_r = min(min_r, i);
                max_r = max(max_r, i);
            }
        }
        if (max_r <= min_r) return 0;
        return max_r - min_r + 1;
    }
};
```