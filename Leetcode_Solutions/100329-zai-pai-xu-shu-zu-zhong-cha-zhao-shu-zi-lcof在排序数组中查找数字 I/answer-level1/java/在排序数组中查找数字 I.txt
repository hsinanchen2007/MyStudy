### 解题思路
这题会二分查找发就够了

### 代码

```java
class Solution {
    /**
    * 既然是排好序，那用二分查找法没毛病吧
    **/
    public int search(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int targetIndex = binarySearch(nums, target);
        int counter = 0;
        if (targetIndex == -1) {
            return counter;
        }
        counter++;
        int len = nums.length;
        for (int i = targetIndex + 1; i < len; i++) {
            if (nums[i] == target) {
                counter++;
                continue;
            }
            break;
        }
        for (int i = targetIndex - 1; i >= 0; i--) {
            if (nums[i] == target) {
                counter++;
                continue;
            }
            break;
        }
        return counter;
    }

    private int binarySearch(int[] nums, int target) {
        int low = 0;
        int high = nums.length - 1;
        while (low <= high) {
            int middle = (low + high) / 2;
            if (nums[middle] > target) {
                high = middle - 1;
            } else if (nums[middle] < target) {
                low = middle + 1;
            } else {
                return middle;
            }
        }
        return -1;
    }
}
```