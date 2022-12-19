**二分查找准确值，若没有准确值，则返回其应该插入的位置**， 正好符合题意。
```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int left=0, right=len-1, mid;
        while(left<=right){
            mid = (right-left)/2+left;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target)
                right = mid-1;
            else
                left = mid+1;
        } 
        return left;
    }
};
```