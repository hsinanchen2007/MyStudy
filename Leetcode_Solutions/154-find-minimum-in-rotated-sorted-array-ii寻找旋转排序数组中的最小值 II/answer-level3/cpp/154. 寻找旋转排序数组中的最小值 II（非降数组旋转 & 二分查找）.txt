### 解题思路
当 nums[low] < nums[high] 时，数组递增，最小值是 nums[low]
当 nums[low] < nums[mid] 时，[low, mid] 是不降的，最小值在 [mid+1, high]中查找
当 nums[low] == nums[mid] 时，没办法确定 num[mid] 左右两个区间是不降的，此时可以有两种做法:
    1. 在[low, high] 中顺序查找最小值
    2. low++
当 nums[low] > nums[mid] 时，[mid, high] 是不降的，此时可以有两种做法：
    1. 判断 nums[mid]是不是最小值，如果不是，则在 [low, mid-1] 中查找最小值
    2. 在[low, mid] 中查找最小值
    
### i
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            if (nums[low] < nums[high]) return nums[low];
            int mid = low + ((high - low) >> 1);
            if (nums[low] < nums[mid]) low = mid + 1;
            else if (nums[low] == nums[mid]) low++;
            else high = mid;
        }
        return nums[high];
    }
};
```

### ii
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            if (nums[low] < nums[high]) return nums[low];
            int mid = low + ((high - low) >> 1);
            if (nums[low] < nums[mid]) low = mid + 1;
            else if (nums[low] == nums[mid]) low++;
            else if (nums[mid] < nums[mid-1]) return nums[mid];
            else high = mid - 1;
        }
        return nums[high];
    }
};
```