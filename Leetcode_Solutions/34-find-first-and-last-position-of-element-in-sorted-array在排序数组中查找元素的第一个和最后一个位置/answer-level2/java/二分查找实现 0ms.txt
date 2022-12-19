### 解题思路
二分查找
### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int len = nums.length;
        int start = 0;
        int end = len - 1;
        int left = -1;
        int right = -1;
        while (start <= end) {
            int middle = (start + end) / 2;
            if (nums[middle] < target) {
                start = middle + 1;
            } else if (nums[middle] > target) {
                end = middle - 1;
            } else {
                int left_temp = middle;
                while (left_temp >= start) {
                    if (nums[left_temp] == target) {
                        left = left_temp;
                        left_temp--;
                    } else {
                        break;
                    }
                }
                int right_temp = middle;
                while (right_temp <= end) {
                    if (nums[right_temp] == target) {
                        right = right_temp;
                        right_temp++;
                    } else {
                        break;
                    }
                }
                break;
            }
        }
        int[] result = new int[2];
        if (left > right) {
            result[0] = -1;
            result[1] = -1;
        } else {
            result[0] = left;
            result[1] = right;
        }
        return result;
    } 
}
```