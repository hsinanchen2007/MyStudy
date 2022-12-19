### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/c613d8f3890607a5463de3f8ff9f5bec04087513a724003408bd8c8ab50b8802-%E6%8D%95%E8%8E%B7.PNG)
动态规划题基本都是要用一维数组或者二维数组来保存历史记录。在这里定义一维数组dp[i]，其含义是以nums[i]结尾的最大子序和。
子问题：
dp[0]：最大子序和就是第一个字母，也就是边界；
dp[1]：他有两种选择，1.nums[0]+nums[1],即dp[0]+nums[1];2.nums[1];
dp[2]：他也有两种选择，1.dp[1]+nums[2];2.nums[2];(不能有dp[1]这种情况，这样子不算连续的了)
···以此类推
边界：dp[0]=nums[0];
初始状态：定义一个m表示dp[0]~dp[i-1]中最大的最大子序和，初始值dp[0];
状态转移方程：dp[i]=max(dp[i-1]+nums[i],nums[i]);

### 代码
法一：时间复杂度O(n),空间复杂度O(n);

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int len=nums.size();
        int m,dp[len]={0};
        dp[0]=nums[0];
        m=dp[0];
        for(int i=1;i<len;i++)
        {
            dp[i]=max(nums[i],dp[i-1]+nums[i]);
            m=dp[i]>m?dp[i]:m;
        }
        return m;
    }
};
```
法二：可以在上面进行优化，dp代表以nums[i]结尾的最大子序和，predp代表以nums[i-1]结尾的最大子序和，dp可以根据predp得出结果；
时间复杂度O(n),空间复杂度O(1);
```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int len=nums.size();
        int m,dp,predp;
        dp=nums[0];
        predp=dp;
        m=dp;
        for(int i=1;i<len;i++)
        {
            dp=max(nums[i],predp+nums[i]);
            predp=dp;
            m=dp>m?dp:m;
        }
        return m;
    }
};
```