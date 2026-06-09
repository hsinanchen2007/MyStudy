![QQ截图20200330173706.png](https://pic.leetcode-cn.com/b90ab32b3f927235f098fec77515382131c10fa3f89be8d319b161178a0fa775-QQ%E6%88%AA%E5%9B%BE20200330173706.png)
numbers[i]取值范围是0-100，声明数组dp[102],dp[index]内存放比index小的值的数量。
```
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int len=nums.size();
        int dp[102]={0};
        for(auto n:nums)
        {
            dp[n+1]++;
        }
        for(int i=1;i<=100;i++)
        {
            dp[i]=dp[i-1]+dp[i];
        }
        vector<int> res(len,0);
        for(int i=0;i<len;i++)
        {
            res[i]=dp[nums[i]];
        }
        return res;
    }
};
```

