![选择数组.png](https://pic.leetcode-cn.com/30968d23c7198269866663c592fee621f6d12b060b9fddd1745b4166e6bc0aa0-%E9%80%89%E6%8B%A9%E6%95%B0%E7%BB%84.png)

```java
class Solution {
    
    // 一定是二分查找思想
    public int search(int[] nums, int target) {
        
        if (nums == null || nums.length < 1) {
            return -1;
        }
        
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            
            // nums[mid]在第1个有序片段
            if (nums[mid] > nums[right]) {
                // target在第1个有序片段
                if (target > nums[mid]) {
                    left = mid + 1;
                }
                // target的位置未知
                else {
                    // target在第1个有序片段
                    if (target > nums[right]) {
                        right = mid - 1;
                    }
                    // target在第2个有序片段
                    else {
                        left = mid + 1;
                    }
                }
            }
            // mid在第2个有序片段
            else {
                // target的位置未知
                if (target > nums[mid]) {
                    // target在第1个有序片段
                    if (target > nums[right]) {
                        right = mid - 1;
                    }
                    // target在第2个有序片段
                    else {
                        left = mid + 1;
                    }
                }
                // target在第2个有序片段
                else {
                    right = mid - 1;
                }
            }
        }
        
        return -1;
    }
}

```
