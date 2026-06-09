二分查找左右边界
```
class Solution {
    int binSearchLeft(vector<int>& nums, int target) { //左边界
        int lo = 0, hi = nums.size()-1; //注意lo,hi取值
        while(lo<hi){
            int mi = (lo+hi)>>1;
            (nums[mi]<target)? lo = mi+1: hi = mi;
        }
        if(nums[hi] != target) return -1;
        return hi;
    }
    int binSearchRight(vector<int>& nums, int target) { //右边界
        int lo =0, hi = nums.size(); //注意lo,hi取值
        while(lo<hi){
            int mi = (lo+hi)>>1;
            (target<nums[mi])? hi = mi: lo = mi+1;
        }
        if(nums[--lo] != target) return -1;
        return lo;
    }
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int left = binSearchLeft(nums, target);
        if(lo == -1) return 0; //没有匹配值返回0
        int right = binSearchLeft(nums, target);
        return right-left+1;
    }
};
```
