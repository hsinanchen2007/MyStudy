```C++
class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        if (nums.empty())   return -1;
        return search(nums, 0, nums.size() - 1);
    }
    int search(vector<int>& nums, int left, int right){
        // 分治 + 二分查找
        if (left >= right){
            if(nums[left] == left)  return left;
            else    return -1;
        }
        int mid = left + (right - left) / 2;
        int ret = 0;
        if (mid == nums[mid]){
            // 当中点符合条件时,还需向前半段去验证是否存在更小符合条件的数
            ret = search(nums, left, mid - 1);
            return ret == -1 ? mid: ret;
        }
        else{
            // 当中点不满足的时候,分别向左半段和右半段递归去找更小的数
            // 当左半段出现的符合条件的数,直接返回右半段就不需要找了
            ret = search(nums, left, mid - 1);
            if (ret != -1)  return ret;
            ret = search(nums, mid + 1, right);
            return ret == -1 ? -1 : ret;
        }
        return -1;
    }
};
```