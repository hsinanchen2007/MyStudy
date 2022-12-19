### 解题思路
最开始以为这个和最大子序列和那道题差不多，就按照那个思路写了一遍，发现没有注意正负号的问题。
由于有负负相乘的问题，于是我想到干脆直接保存每个节点子序列的最大值和最小值，最大值、最小值一定出现在nums[i]、nums[i]*dp[i]->最大值、nums[i]*dp[i]->最小值之间。最后求出解。
写完了突然觉得我的方法也不算DP啊，只算是借鉴了dp的思路吧，我也没学过dp，就是做了几道题，一会看看别人怎么做的

### 代码

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len=nums.size();
        map<int,pair<int,int>> mp;//first->max second->min
        mp[0]=make_pair(nums[0],nums[0]);
        int res=nums[0];
        for(int i=1; i<len; ++i)
        {
            int first_=mp[i-1].first*nums[i];
            int second_=mp[i-1].second*nums[i];
            int max_=max(max(first_,second_),nums[i]);
            int min_=min(min(first_,second_),nums[i]);
            if(max_>res) res=max_;
            mp[i]=make_pair(max_,min_);
        }
        return res;
    }
};
```