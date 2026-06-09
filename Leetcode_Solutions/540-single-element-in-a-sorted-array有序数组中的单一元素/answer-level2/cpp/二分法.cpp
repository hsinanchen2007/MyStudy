```
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right){
            int mid=(left+right)/2;
            if(mid==0||mid==nums.size()-1||(nums[mid]!=nums[mid+1]&&nums[mid]!=nums[mid-1])){
                return nums[mid];
            }
            if(nums[mid]==nums[mid+1]){
                if((mid-left)%2==0){
                    left=mid+2;
                }
                else{
                    right=mid-1;
                }
            }
            else{
                if((right-mid)%2==0){
                    right=mid-2;
                }
                else{
                    left=mid+1;
                }
            }

        }
        return nums[left];
    }
};
```
