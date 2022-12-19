```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3) return nums.size();
        int l=0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;i++){
            l = i+2;
            while(l< nums.size() and nums[l] == nums[i]) {
                nums.erase(nums.begin()+l);
            }
        }
        return nums.size();
    }
};
```
