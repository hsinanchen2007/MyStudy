### 解题思路
先将第一个点定住，然后再通过两个游标来判断是否符合预期结果。

### 代码

```cpp
class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        sort(nums.begin(),nums.end());//排序
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-2;++i){//后面两个留给游标
            if(nums[i]>0) break;//不可能情况
            if(i>0&&nums[i]==nums[i-1]) continue;//定位点值相同的跳过
            int l=i+1;
            int h=n-1;
            while(l<h){
                int s=nums[i]+nums[l]+nums[h];
                if(s>0) --h;
                else if(s<0)++l;
                else
                {
                    ans.push_back({nums[i],nums[l],nums[h]});
                    while(l<h && nums[l]==nums[++l]);
                    while(l<h && nums[h]==nums[--h]);
                }
                
            }
        }
        return ans;
    }
};
```