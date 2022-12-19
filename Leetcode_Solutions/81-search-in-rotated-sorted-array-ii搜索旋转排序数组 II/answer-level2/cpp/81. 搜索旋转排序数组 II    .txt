### 解题思路


### 代码

```cpp
/*class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int right=nums.size()-1;
        int left=0;
        while(left<=right){
            int mid=left+(right-left)>>1;
            if(nums[mid]==target) return true;
            if(left<right&&nums[left]==nums[right]) right--;
            else if(nums[mid]<nums[right]){
                if(target>nums[mid]&&target<nums[right]){
                    left=mid+1;
                }
                else right=mid-1;
            }
            else if(nums[mid]>nums[right]){
                if(target<nums[mid]&&target>nums[left]){
                    right=mid-1;
                }
                else left=mid+1;
            }
        }
        return false;
    }
};*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            while(left!=right && nums[left]==nums[right]) right--; //无重复值的解法中添加这行
            int mid=(left+right)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]>target){
                if(nums[mid]>nums[right] && target<nums[left]) left=mid+1;
                else right=mid-1;
            }else{
                if(nums[mid]<nums[left] && target>nums[right]) right=mid-1;
                else left=mid+1;
            }
        }
        return false;
    }
};

```