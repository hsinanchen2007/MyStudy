这道题思路上其实比较简单，利用旋转数组的部分有序性仍然是可以使用二分法的，只要兼顾一些特殊情况即可成功AC。
第一次做这道题花了很久的时间，其实主要还是二分法的边界条件不熟悉的原因，提升改正意识成功通过，时间效率超过100%。
```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0, end = nums.size(), last = nums.size()-1;
        if(nums.size()==0) return -1;
        while(begin+1<end){
            int mid = begin+(end-begin)/2;
            if(nums[mid]<=nums[last]){
                if(target>=nums[mid]&&target<=nums[last]) begin = mid;
                else end = mid;
            }
            else{
                if(target<nums[mid]&&target>nums[last]) end = mid;
                else begin = mid;
            }
        }
        if(nums[begin] == target) return begin;
        else return -1;
    }
};
```
