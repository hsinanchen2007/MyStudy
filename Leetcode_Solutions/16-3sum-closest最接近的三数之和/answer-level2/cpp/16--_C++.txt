
### 代码

```cpp
class Solution{
public:
    int threeSumClosest(vector<int>& nums, int target){
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int clo=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;++i){
            if(i>0&&nums[i]==nums[i-1]) continue;
            int l=i+1;
            int h=n-1;
            while(l<h){
                int tmp=nums[i]+nums[l]+nums[h];
                if(abs(tmp-target)<abs(clo-target))
                    clo=tmp; 
                if(tmp<target) ++l;
                else if(tmp>target) --h;
                else return target;
            }
        }
        return clo;
    }
};
```