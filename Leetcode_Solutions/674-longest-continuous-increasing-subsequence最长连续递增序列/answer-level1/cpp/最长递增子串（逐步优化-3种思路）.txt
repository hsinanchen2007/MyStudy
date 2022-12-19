+ 暴力枚举：O(n^2)

+ 动态规划：T(n)=O(n)，S(n)=O(n)

  + 状态定义：dp(i)表示以A[i]为结尾的最长递增子串的长度（开头可变）
  + 状态转移：

    $$
    dp(i) =
    \begin{cases} 
    dp(i-1)+1,  & \text{A[i-1]<A[i]} \\
    1, & \text{A[i-1]}\ge A[i]
    \end{cases}
    $$

  + base case：dp(0)=1

```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size(),1); // 初始化为1
        for (int i=1; i < nums.size(); i ++) { // 动态规划：dp[i]表示以nums[i]为结尾的最长递增子串
            if (nums[i-1] < nums[i]) dp[i] = dp[i-1] + 1;
        }
        return *max_element(dp.begin(),dp.end());
    }
};
```

+ 双指针：T(n)=O(n)，S(n)=O(n)
  + 定义i和j分别指向LCIS的起止元素，ans记录最大值
  + 若A[j-1]>=A[j]，出现断层，令i=j，ans=max(ans,i-j)。
  + 指针j++
```
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i=0, j=1, ans=1;
        while (j < nums.size()) { // 双指针
            if (nums[j] <= nums[j-1]) { // 出现断层更新
                ans = max(ans, j-i);
                i = j;
            }
            else if (j == nums.size()-1) ans = max(ans, j-i+1); // 结尾更新
            j ++;
        }
        return ans;
    }
};
```