### 解题思路
两种方法：
1.暴力解：遍历所有求最小值
2.二分查找：
参考
153. 寻找旋转排序数组中的最小值
https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/153-xun-zhao-xuan-zhuan-pai-xu-shu-zu-zhong-de-10/

由于存在重复元素，会出现nums[mid] == nums[right] 的场景，导致无法判断mid是在左侧还是在右侧。
当 nums[mid] == nums[right] 时，nums[right]如果是最小值，一定不是唯一最小值，因为还存在nums[mid]
因此nums[mid] == nums[right]，right--

### 代码

```cpp
class Solution {
public:
    int findMin(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                right--;
            }
        }

        return nums[left];
    }
};
```