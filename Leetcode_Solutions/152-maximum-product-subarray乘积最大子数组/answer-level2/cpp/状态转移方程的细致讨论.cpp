### 解题思路
+ 关键点：乘积有负负得正，因此最大乘积和最小乘积之间有关系。再仔细想就能发现需要维护``maxx[]``和``minn[]``两个数组。
+ 状态：``maxx[i]``代表以nums[i]结尾的最大子数组乘积，``minn[i]``代表以nums[i]结尾的最小子数组乘积。（很多子序列、子串、子数组有关的问题，若是一维dp形式则很多都是``dp[i]``代表以nums[i]结尾的××值）
+ 状态转移方程：我想得比较细致。分类如下面代码所写，其实也都是自己分情况讨论、合并情况以后的结果。另外注意``minn[i]≤maxx[i]``的结论。其实简单来看也可以这么写：

        maxx[i] = max(maxx[i - 1] * nums[i], minn[i - 1] * nums[i], nums[i]);
        minn[i] = min(minn[i - 1] * nums[i], maxx[i - 1] * nums[i], nums[i]);



### 代码

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        vector<int> maxx(n), minn(n);
        maxx[0] = minn[0] = nums[0];
        int ans = maxx[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] >= 0) {
                if(maxx[i - 1] > 0) {
                    maxx[i] = nums[i] * maxx[i - 1];
                }
                else maxx[i] = nums[i];
                minn[i] = nums[i] * minn[i - 1];
            }
            else {
                maxx[i] = nums[i] * minn[i - 1];
                if(maxx[i - 1] <= 0) minn[i] = nums[i];
                else minn[i] = maxx[i - 1] * nums[i];
            }
            ans = max(ans, maxx[i]);
        }
        return ans;
    }
};
```