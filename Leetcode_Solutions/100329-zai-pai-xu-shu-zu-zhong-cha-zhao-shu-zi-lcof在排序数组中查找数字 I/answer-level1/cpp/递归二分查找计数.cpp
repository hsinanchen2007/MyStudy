### 解题思路
对[lo, hi)区间递归二分查找，始终保持左闭右开区间，递归地在[lo, mid)和[mid+1, hi)查找目标值，若存在返回1，否则返回0

### 代码

```cpp
class Solution {
public:
    int binarysearch(vector<int> &nums, int lo, int hi, int &target)
    {
        if(lo >= hi)return 0;  //递归结束条件
        int mid = (lo + hi)/2;
        if(nums[mid] == target)
        {
            return 1 + binarysearch(nums, lo, mid, target) + binarysearch(nums, mid+1, hi, target);
        }
        else if(target > nums[mid])
        {
            return binarysearch(nums, mid+1, hi, target);
        }
        else
        {
            return binarysearch(nums, lo, mid, target);
        }
    }
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)return 0;
        int low = 0, high = nums.size();  //左闭右开区间
        return binarysearch(nums, low, high, target);
    }
};
```