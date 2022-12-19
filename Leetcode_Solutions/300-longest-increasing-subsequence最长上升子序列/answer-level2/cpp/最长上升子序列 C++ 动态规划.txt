### 解题思路
![image.png](https://pic.leetcode-cn.com/c4ddd8b9c3a71a80a23ec7b54a302b03d6abdaed8ad57bbba76e4cbe70ac7c4e-image.png)
动态规划法，创建一个pair<int,int>类型的数组dp，pair.first代表nums的元素，pair.second代表从0到当前元素为止的最长上升子序列长度.
状态转移方程如下。
dp[i].first=nums[i];
dp[i].second=max(dp[j1].second+1,dp[j2].second+1,……,dp[jn].second+1)  nums[i]>nums[j1],nums[j2],nums[j3]……nums[jn]
最后遍历一遍dp数组，找出最大的second元素就好了
### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<pair<int ,int>> dp;
        bool f;
        int max;
        for(auto i:nums)
        {
            f=false;
            max=0;
            for(auto j:dp)
                if(i>j.first&& j.second+1>max) max=j.second+1;//找从0到当前元素为止的最长上升子序列长度
            dp.push_back(make_pair(i,max==0?1:max));//状态转移
        }
        int res=0;
        for( auto n:dp)
            if(n.second>res) res=n.second;//找结果
        return res;
    }
};
```