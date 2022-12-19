与上一题一样,仍然用二分法

当`nums[mid] > nums[right]`说明在`mid`左半边的递增区域, 说明最小元素在`> mid`区域

当`nums[mid] < nums[right]`说明在mid右半边的递增区域, 说明最小元素在`< mid`区域

当`nums[mid] = nums[right]`,我们让`right - 1`, 有种向`left`靠拢的感觉

这当然影响复杂度, 比如 数组为 `[2, 2, 2, 2,...,2]`用这算法要$O(n)$

小技巧: 

一般是这样,

当`while left < right`是循环外输出

当`while left <= right`是循环里输出

------

相关题型: [153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)

## 代码:

```python []
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] > nums[right]:
                left = mid + 1
            elif nums[mid] < nums[right]:
                right = mid
            else:
                right -= 1
        return nums[left]
```



```java []
class Solution {
    public int findMin(int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) left = mid + 1;
            else if (nums[mid] < nums[right]) right = mid;
            else right--;

        }
        return nums[left];
    }
}
```

