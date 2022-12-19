```
class Solution {
public:
    bool find(int left,int right,int num,vector<int>&nums){
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]==num){
                return true;
            }
            if(nums[mid]>num){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return false;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            int now=nums[i];
            int res=target-now;
            if(find(i+1,nums.size(),res,nums)){
                return {now,res};
            }
        }
        return {};
    }
};
```

