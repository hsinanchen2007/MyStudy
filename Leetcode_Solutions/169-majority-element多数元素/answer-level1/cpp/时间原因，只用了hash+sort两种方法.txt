```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // hash 空间复杂度 
        // unordered_map<int,int>mp;
        // int len = nums.size();
        // for(auto &i:nums){
        //     mp[i]++;
        //     if(mp[i] > len/2 ) return i;
        // }

        // sort
        int len = nums.size();
        sort(nums.begin(),nums.end());
        return nums[len/2];

        return 0;
    }
};
```
