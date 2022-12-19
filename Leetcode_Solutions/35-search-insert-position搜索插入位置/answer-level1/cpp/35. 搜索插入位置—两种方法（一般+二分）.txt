方法一
```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target<nums[0]) return 0;
        if(nums[nums.size()-1]<target) return nums.size();
        int ans;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==target) return i;
            if(nums[i]<target&&target<nums[i+1]) ans=i+1;
        }
        if(nums[nums.size()-1]==target) return nums.size()-1;
        return ans;
    }
};
```
方法二 二分查找 
```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target<nums[0]) return 0;
        if(nums[nums.size()-1]<target) return nums.size();
        int left=0,right=nums.size()-1,mid=0,tmp=0;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]==target) break;
            else if(nums[mid]<target) left=mid+1;
            else right=mid-1;
        }
        if(nums[mid]>target){
            while(mid>=0){
                if(nums[mid]<target) return mid+1;
                mid--;
            }
        } 
        if(nums[mid]<target){
            while(mid<nums.size()){
                if(nums[mid]>target) return mid;
                mid++;
            }
        } 
        return mid;
    }
};
```
