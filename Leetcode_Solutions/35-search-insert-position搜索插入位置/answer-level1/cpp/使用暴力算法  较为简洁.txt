`
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;
        for(;i<n;i++){
            if(nums[i]>=target){
               break;
            }
        }
        return i;
    }
};

`