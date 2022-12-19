```
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1||nums[0]<nums.back())
            return nums[0];
            for(int i=1;i<nums.size();i++){
                if(nums[i]<nums[i-1])
                    return nums[i];
            }
            return nums.back();
           
    }
};
```
