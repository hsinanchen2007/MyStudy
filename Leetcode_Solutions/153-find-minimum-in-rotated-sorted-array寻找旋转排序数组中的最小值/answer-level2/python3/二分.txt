## 思路:

二分法, 二分法就是找与`mid`判断条件,这里我们选用`right`

当`nums[mid] > nums[right]`说明在`mid`左半边的递增区域, 说明最小元素在`> mid`区域

当`nums[mid] <= nums[right`说明在mid右半边的递增区域, 说明最小元素在`<= mid`区域

小技巧: 

一般是这样,

当`while left < right`是循环外输出

当`while left <= right`是循环里输出

------

相关题型: [154. 寻找旋转排序数组中的最小值 II](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/)

## 代码:

```python []
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1 
        while left < right:
            mid = left + (right - left) // 2
            if nums[right] < nums[mid]:
                left = mid + 1
            else:
                right = mid 
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
            else right = mid;
        }
        return nums[left];
    }
}
```



