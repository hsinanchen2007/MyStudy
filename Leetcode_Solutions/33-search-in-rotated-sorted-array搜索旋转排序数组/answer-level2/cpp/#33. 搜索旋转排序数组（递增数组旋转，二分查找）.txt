### 解法一
如果 nums[low] <= nums[mid]，说明 [low, mid-1] 区间是递增的，否则 [mid+1, high]是递增的，判断 target 是位于递增区间还是非递增区间，进而更新查找区间大小。
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() -1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] == target) return mid;
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
```

### 解法二
搜索出该旋转数组的最小值的位置，从而找到了两个递增区间。 此时可以：
1、可以用模运算将递增旋转数组映射成虚拟的递增无旋转数组，然后在这个虚拟数组中进行二分查找。
2、判断出 target 在两个递增区间中的哪一个，在那个递增区间做二分查找。
```cpp
// 计算 virtual_low, virtual_high, virtual_mid，就像有两个完全一样的数组拼接在一起
// 比较的时候要映射回实际位置 real_mid

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) return -1;
        if (size == 1) return (target == nums[0] ? 0 : -1); 
        int offset = 0;

        // 如果 offset > 0 则用二分查找计算 offset
        if (nums.front() > nums.back()) {
            int low = 0;
            int high = size - 1;
            while (low <= high) {
                int mid = low + ((high - low) >> 1);
                if (nums[mid] > nums[mid+1]) {
                    offset = mid + 1;
                    break;
                } else {
                    if (nums[mid] < nums[low]) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
        }

        int virtual_low = offset;
        int virtual_high = (offset + size - 1);

        while (virtual_low <= virtual_high) {
            int virtual_mid = virtual_low + ((virtual_high - virtual_low) >> 1);
            int real_mid = virtual_mid % size;
            if (target == nums[real_mid]) {
                return real_mid;
            } else if (target < nums[real_mid]) {
                virtual_high = virtual_mid - 1;
            } else {
                virtual_low = virtual_mid + 1;
            }
        }
        return -1;
    }
};
```