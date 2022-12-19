- 暴力枚举是指数级的，不可取。
- 事实上暴力枚举包含了大量重复计算，找到重复计算并优化是我们的目标。
- 不妨先看看动态规划的解法，自然能明白重复来自哪。
- 首先定义状态：dp[i]含义是以元素nums[i]结尾的最长LIS的长度，注意一定是以nums[i]结尾。
- 有两种方式转移状态，具体参见代码。
```
代码块
#include <algorithm>
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }
        int len = nums.size();
        int dp[len];
        int maxlength =-1;
        for(int i=0;i<len;i++){
            dp[i] = 1;
            for(int j=0;j<i;j++)
                if(nums[i] > nums[j] && dp[j]+1 >dp[i]){
                    dp[i]=dp[j]+1;
                }
            maxlength = max(maxlength,dp[i]);
        }
        return maxlength;
    }
};
```
就不写数学语言了，写点轻松的。
- 可以想象自己是数组的某一个元素i，并且身高是对应的值，往前往后看。当大哥的条件是最高，且二哥比三哥高，以此类推。往前看有i-1个队伍。一个一个找队伍，要找遍队伍需要找i-1次。
- 有两种方式当大哥，第一找个队伍：你比他们老大都高，这样你当老大，队伍人数加一。
- 第二自己单干：找了i-1次，没有前面所有队伍的老大高。
- 边界条件：dp[i]=1;最起码能自己单干。

