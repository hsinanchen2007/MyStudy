### 解题思路
![image.png](https://pic.leetcode-cn.com/d37b7607cf5197f78515d273874c11a7ad1ba2a4302f839b99d0cc599a9d528c-image.png)

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return new int[]{-1, -1};
        }

        int first = -1, second = -1;
        int start = 0, end = nums.length - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (nums[start] == target) {
            first = start;
        } else if (nums[end] == target) {
            first = end;
        }

        start = 0;
        end = nums.length - 1;

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (nums[end] == target) {
            second = end;
        } else if (nums[start] == target) {
            second = start;
        }

        return new int[]{first, second};
    }
}
```