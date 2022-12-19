
```C++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(!nums.size()) return -1;
        int index = -1;
        bSearch(nums,0,nums.size()-1,target,index);
        return index;
    }
    void bSearch(vector<int>& nums,int left,int right,int target,int& index){
        if(left>right) return;
        int mid = left + (right - left)/2;
        if(nums[mid]==target) index = mid;
        if(nums[mid]>target) bSearch(nums,left,mid-1,target,index);
        if(nums[mid]<target) bSearch(nums,mid+1,right,target,index);
    }
};
```
