### 解题思路
题目描述中的数组特性是两段递增，前一段所有数据比第二段的大

依据特性，可二分，
1. left与mid间单调递增，nums[mid] < target，left左移至mid + 1，简言之就是最大的都没有target大，不再[left, mid]之间；
2. mid与right间单调递增，nums[mid] > target，right右移至mid - 1，简言之就是最小的都比target小，不再[mid, right]之间；
3. 都不是递增区间，left++， right--，进行缩进

### 代码

```java
class Solution {
    // 二分查找
    public int search(int[] nums, int target) {
        if (nums.length <= 0) return -1;
        
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            if (nums[left] == target) return left;
            else if (nums[right] == target) return right;
            else {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target) return mid;
                else if (nums[left] < nums[mid] && nums[mid] < target) left = mid + 1;
                else if (nums[mid] < nums[right] && nums[mid] > target) right = mid - 1;
                else {
                    left++;
                    right--;
                }
            }
        }
        return -1;
    }
}
```