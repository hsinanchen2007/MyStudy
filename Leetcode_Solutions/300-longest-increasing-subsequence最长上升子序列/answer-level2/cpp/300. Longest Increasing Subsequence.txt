### 解题思路
DP
解题思路和279.perfect squares 是一样的.
![image.png](https://pic.leetcode-cn.com/b228a38303dbcb3fefd74cf815f261d551a105c4c6b873e12dca9e82b7473a7a-image.png)


### 代码

```cpp
class Solution {
public:
    //dp[i], 以索引i结尾的最长上升子序列的长度，必须能取到i.
    //求解每个状态都不是常量时间，与自己规模i成正比.
    //dp[i] = max(dp[i], dp[j] + 1), j -> [0, i).
    //时间复杂度O(n2)与一些二维状态表达式的题一样.
    int lengthOfLIS(vector<int>& nums) {
        int maxLength = 1;
        if(nums.size() == 0)
            return 0;
        //初始化每个索引上面的长度为1
        vector<int> dp(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
               maxLength = max(maxLength, dp[i]); 
            }
        }
        return maxLength;
    }
};
```

### 解题思路
二分查找


### 代码

```cpp

```