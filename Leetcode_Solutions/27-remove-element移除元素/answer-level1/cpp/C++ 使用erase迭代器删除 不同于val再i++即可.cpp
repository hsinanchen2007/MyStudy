```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i=0; i<nums.size();){
            if(nums[i] == val)  nums.erase(i+nums.begin());
            else i++;
        }
        return nums.size();
    }
};
```
