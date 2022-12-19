### 解题思路

前n个元素组成的连续子序列的最大和可能为
        (1)前n-1个元素组成的连续子序列的最大和
        (2)以第n-1项为尾项的所有连续子序列中的最大和+nums[n]
        (3)nums[n]
前1个元素组成的序列中连续子序列的最大和是 nums[0]
    最大和能与nums[i]相加的必要条件是,最大和对应的连续子序列的最后一项为nums[i-1]
    所以还要获得以nums[i-1]为最后一项的连续子序列的最大和
    **以第1项为尾项的所有连续子序列中的最大和是 dp[0]=nums[0]
    **以第2项为尾项的所有连续子序列中的最大和是 dp[1]=max(dp[0]+nums[1], nums[1])
    **以第3项为尾项的所有连续子序列中的最大和是 dp[2]=max(dp[1]+nums[2], nums[2])
状态方程：
    dp(x)表示以第x项为尾项的连续子序列的最大值
    dp(n)=max(dp(n-1)+nums[n], nums[n]), dp(0)=nums[0].
    f(n)=max(f(n-1), dp(n-1)+nums[n], nums[n])
        =max(f(n-1),dp(n)), f(0)=nums[0].


### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len=nums.size();
        if(nums.size()==0) return 0;
        int dp[len];
        dp[0]=nums[0];  //以当前值为尾部的“和最大”连续子序列的初始状态
        int max_result=nums[0]; //当前搜索到的连续序列最大和的初始状态
        for(int i=1; i<len; i++){
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            max_result = max(dp[i], max_result);
        }
        return max_result;
    }
};
```