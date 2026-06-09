

### 代码

```cpp
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) 
    {
        int res=INT_MAX;//记录最终结果

        unordered_map<int,int> m;
        for(int n:nums) m[n]++;//统计每个数出现的次数

        vector<int> max_n;//用于记录出现次数最多的数（可能不是一个数）
        int temp=0;
        for(auto a:m)
        {
            if(a.second>temp) { max_n.clear();max_n.push_back(a.first);temp=a.second; }
            else if(a.second==temp) max_n.push_back(a.first);
        }

        for(int n:max_n)
        {
            int lo=nums.size(),hi=0;//记录每个数出现的最小和最大位置
            for(int i=0;i<nums.size();i++)
                if(nums[i]==n)
                {
                    lo=min(lo,i);
                    hi=max(hi,i);
                }
            res=min(res,hi-lo+1);
        }

        return res;
    }
};
```