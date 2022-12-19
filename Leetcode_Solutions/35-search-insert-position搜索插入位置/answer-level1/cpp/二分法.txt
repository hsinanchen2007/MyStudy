执行用时 :4 ms, 在所有 C++ 提交中击败了96.04% 的用户
内存消耗 :6.5 MB, 在所有 C++ 提交中击败了100.00%的用户
```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        int mid=(left+right)/2;
        while(left<=right)
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target){
                right=mid-1;
                mid=(left+right)/2;
            }
            else{
                left=mid+1;
                mid=(left+right)/2;
            }
        if(target<nums[0])//美中不足是如果目标小于首元素要特殊处理
            return 0;
        else
            return mid+1;
    }
};
```
