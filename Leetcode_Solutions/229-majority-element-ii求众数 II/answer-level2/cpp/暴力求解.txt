
```
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> resV;
        if(n<1) return resV;
        sort(nums.begin(),nums.end());
        int res=nums[0];
        int rescount=0;
        int re_sign = n/3;
        for(int i=0; i<n; ++i) {
            if(res==nums[i]) {
                ++rescount;
                if((rescount-re_sign)==1) {
                    resV.push_back(res);
                }
            } else {
                rescount = 1;
                res = nums[i];
                if((rescount-re_sign)==1) {
                    resV.push_back(res);
                }
            }
        }
        return resV;
    }
};
```
