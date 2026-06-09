### 解题思路
此处撰写解题思路
与之前那道最大连续数和完全相同，只需要检测加上当前的num[i]之后是否比dp[i-1]大即可
![QQ截图20200320190643.png](https://pic.leetcode-cn.com/39c73b144c4a59438db567b33d06b774255dddfb0a8c222240a9a6c9a51015c4-QQ%E6%88%AA%E5%9B%BE20200320190643.png)


### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int result=INT_MIN;
    int len=nums.size();
    vector<int>dp(len);
    dp[0]=nums[0];
    result=dp[0];
    for(int i=1;i<len;i++){
        dp[i]=max(dp[i-1]+nums[i],nums[i]);
        result=max(result,dp[i]);
    }
    return result;

    }
};
```