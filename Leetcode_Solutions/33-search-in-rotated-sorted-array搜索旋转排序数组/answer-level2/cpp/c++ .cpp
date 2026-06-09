### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }

    int binarySearch(vector<int>& nums, int target, int l, int h){
        if(l > h)
            return -1;

        int mid = l + (h - l) / 2;

        if(nums[mid] == target)
            return mid;
        
        if (nums[l] <= nums[mid]) {
            if(nums[l] <= target && nums[mid] >= target)
                return binarySearch(nums, target, l, mid - 1);
            else
                return binarySearch(nums, target, mid+1, h);
        }else {
            if(nums[mid] <= target && target <= nums[h])
                return binarySearch(nums, target, mid + 1, h);
            else
                return binarySearch(nums, target, l, mid - 1);
        }
    }
    
};
```