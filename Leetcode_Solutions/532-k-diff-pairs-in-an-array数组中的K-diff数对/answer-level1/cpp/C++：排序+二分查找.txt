### 参考思路
首先将数组排序，随后从小到大遍历数组中的元素，对于每一个元素，向其右侧二分查找k+nums[i]，因为向其左侧查找得到的nums[i]-k一定是在更早之前被发现的（nums[i]-k）+k。
如果当前元素和其前一个元素相等，那么其找到的结果也必然和前一个元素相等，是重复结果，因此直接跳过该元素。
采用二分查找在当前元素右侧区间查找k+nums[i]。这里采用lower_bound()函数查找第一个大于等于k+nums[i]的数，如果没找到，说明右侧最大值小于k+nums[i]，此时可直接结束遍历，返回结果。如果找到，判断找到的结果是否是k+nums[i]，如果是，则计数加1
### 参考代码
```cpp
class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;++i)
        {
            if(i!=0&&nums[i]==nums[i-1])
                continue;
            auto it=lower_bound(nums.begin()+i+1,nums.end(),k+nums[i]);
            if(it==nums.end())//查找失败,说明此刻数组中最大值比nums[i]+k小，因此无需再进行查找
                break;
            if(*it==k+nums[i])
                ++ans;
        }
        return ans;
    }
};
```
