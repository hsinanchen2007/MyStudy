### 解题思路
只比我153题的题解多判断了一个 nums[mid] = nums[right] 的情况而已。

### 法1 - 二分

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, mid, right = nums.size() - 1;

        while(left < right) {
            mid = left + (right - left) / 2;

            // nums[mid] < nums[right]，即 [mid, right] 有序，[left, mid] 可能有序可能无序，
            // 此时最小值在区间 [left, mid] 中，
            // eg: [3, 4, 1, 2, 2, 3, 3] or [1, 2, 2, 3, 3, 3, 4] 
            if(nums[mid] < nums[right]) right = mid;
            
            // nums[mid] > nums[right]，即 [left, mid] 有序，[mid, right] 一定无序，[mid + 1, right] 可能有序可能无序，
            // 此时最小值在区间 [mid + 1, right] 中，
            // eg: [3, 3, 3, 4, 1, 2, 2]
            else if(nums[mid] > nums[right]) left = mid + 1;

            // nums[mid] = nums[right]，此时 [left, mid] 和 [mid, right] 的情况无法确定，
            // 这时只需放缩右边界即可，因为 中间数 = 右边界，放缩了一个右边界，中间数还是存在的，并不影响结果，
            // 把中间数留给后面的 while 循环比较即可，
            // eg: [1, 3, 3, 3]  or [3, 3, 1, 3]
            else right--;
        }

        // 题目没给数组为空的情况，那么非空数组一定存在最小值
        return nums[left];
    }
};
```

### 法2 - 分治

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);
    }

private:
    int findMin(vector<int>& nums, int left, int right) {
        // 数组中只有 1 个元素或只有 2 个元素，直接比较即可
        if(left + 1 >= right) return nums[left] < nums[right] ? nums[left] : nums[right];

        // nums[left] < nums[right]，即有序数组，直接返回左边界即可
        if(nums[left] < nums[right]) return nums[left];

        // 分治解决子问题
        int mid = left + (right - left) / 2;
        return min(findMin(nums, left, mid - 1), findMin(nums, mid, right));
    }
};
```