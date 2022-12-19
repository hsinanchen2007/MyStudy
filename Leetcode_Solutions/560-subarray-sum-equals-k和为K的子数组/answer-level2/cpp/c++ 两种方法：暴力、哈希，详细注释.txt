### 解题思路
map的思路：
    要求相邻子区间的和为k的次数，可以转化为求区间[lefe,right]的和，假设[0,right]的和为sum，[0,left]的和为sum-k，则区间[lefe,right]的和实质上就为[0,right]的和 **减** [0,left]的和。

### 代码

```cpp
class Solution {
public:
/**********************方法2：map****************/
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size(),sum = 0,res = 0;
        mp[0] = 1; //这里初始化的意思:假设区间[1,2,3],k=6,则要求mp[sum(1+2+3)-6] = 1;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i]; //求取每个[0,rignt]的和sum
            if(mp.count(sum-k)) //判断是否[0,left]是否存在，若存在，在将该区间存在的次数累加到res;
            {
                res += mp[sum-k]; //这里sum是不断变化的，所以要一直叠加mp[sum-k],例:[1,2,3,3],k=6，要累加mp[0]和mp[3]的次数
            }
            mp[sum]++;//将每个[0,right]的和出现的次数相加
        }
        return res;
    }
};
/***************************方式1:暴力************************
int subarraySum(vector<int>& nums, int k) {
        int res = 0,sum = 0;
        int n = nums.size();
        for(int i = 0; i < n;i++)
        {
            for(int j = i; j < n;j++)
            {
                sum += nums[j];
                if(sum == k)
                {
                    res++;
                }
            }
            sum = 0;
        }
        return res;
    }
*/

```