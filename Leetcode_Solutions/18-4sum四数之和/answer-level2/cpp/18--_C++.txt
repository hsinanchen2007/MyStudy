### 解题思路
和三数之和相同的思想，只不过是多了一层循环

### 代码

```cpp
class Solution{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        if(n<4) return ans;
        for(int i=0;i<n-3;++i){
            if(i>0&& nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;++j){
                if(j>i+1&& nums[j]==nums[j-1]) continue;
                int l=j+1,h=n-1;
                while(l<h){
                    int tmp=nums[i]+nums[j]+nums[l]+nums[h];
                    if(tmp<target) ++l;
                    else if(tmp>target) --h;
                    else
                    {
                        ans.push_back({nums[i],nums[j],nums[l],nums[h]});
                        while(l<h &&nums[l]==nums[++l]);
                        while(l<h &&nums[h]==nums[--h]);
                    }
                }
            }
        }
        return ans;
    }
};
```