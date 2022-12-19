### 解题思路
题目四排序数组，首先想到的就是二分法；找到左匹配位置，向后挨个匹配，直到不一致结束。

![image.png](https://pic.leetcode-cn.com/ff020ccc0bb3dedc481a3b780231bddce893968d168ae599f54f8e27f35ef607-image.png)


### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        // 异常情况
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int start = 0;
        int end = nums.length - 1;
        while (start <= end) {
            int mid = start + ((end - start) >> 1);
            if (nums[mid] >= target) {
                end = mid - 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            }
        }
        // 没找到
        if (start >= nums.length || nums[start] != target) {
            return 0;
        }
        // 找到左边
        int count = 0;
        while (start <= nums.length - 1) {
            if (nums[start] != target) {
                break;
            } else {
                start++;
                count++;
            }
        }
        return count;
    }
}
```