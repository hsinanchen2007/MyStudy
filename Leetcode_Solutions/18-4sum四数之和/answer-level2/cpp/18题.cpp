```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int a,b,c,d, size=nums.size();
        if(size<4) return res;
        for(int a=0; a<=size-4; a++){
            if(a>0&&nums[a]==nums[a-1]) continue; // 防止出现重复解
            for(int b=a+1; b<=size-3; b++){
                if(b>a+1&&nums[b]==nums[b-1]) continue;
                c=b+1;
                d=size-1;
                while(c<d)
                if(nums[a]+nums[b]+nums[c]+nums[d]<target)
                    c++;
                else if(nums[a]+nums[b]+nums[c]+nums[d]>target)
                    d--;
                else{
                    res.push_back({nums[a],nums[b],nums[c],nums[d]});
                    while(c<d&&nums[c+1]==nums[c])
                        c++;
                    while(c<d&&nums[d-1]==nums[d])
                        d--;
                    c++;
                    d--;
                }
            }
        }
        return res;
    }
};
```
