
二分法，查找区间左和查找区间右


```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())return {-1,-1};
        int left=lowBound(nums,target);
        int right=highBound(nums,target);
        return {left,right};
    }
    int lowBound(vector<int>& nums,int target){
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                high=mid-1;
            }else if(nums[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        if(low>=nums.size() ||nums[low]!=target )return -1;
        return low;
    }

    int highBound(vector<int>& nums,int target){
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<target){
                low=mid+1;
            }else if(nums[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        if(high<0 || nums[high]!=target)return -1;
        return high;
    }
};
```