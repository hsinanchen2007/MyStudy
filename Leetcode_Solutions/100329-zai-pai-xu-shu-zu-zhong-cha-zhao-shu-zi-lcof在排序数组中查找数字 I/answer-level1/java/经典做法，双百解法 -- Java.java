### 解题思路
1.获得头target
2.获得尾target
3.两个差值

### 代码

```java
class Solution {
 public int search(int[] nums, int target) {
        int begin = 0;
        int end = nums.length - 1;
        int first = getFirstTarget(nums, target, begin, end);
        int last = getLastTarget(nums, target, begin, end);
        if (last == -1 || first == -1) {
            return 0;
        }

        return last - first + 1;
    }

    private int getFirstTarget(int[] nums, int target, int begin, int end) {
        while (begin <= end) {
            int mid = begin + (end - begin) / 2;
            if (nums[mid] == target) {
                if ((mid == 0 || nums[mid - 1] != target)) {
                    return mid;
                } else {
                    end = mid - 1;
                }

            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        return -1;
    }

    private int getLastTarget(int[] nums, int target, int begin, int end) {
        while (begin <= end) {
            int mid = begin + (end - begin) / 2;
            if (nums[mid] == target) {
                if ((mid == nums.length - 1 || nums[mid + 1] != target)) {
                    return mid;
                } else {
                    begin = mid + 1;
                }

            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        return -1;
    }
}
```