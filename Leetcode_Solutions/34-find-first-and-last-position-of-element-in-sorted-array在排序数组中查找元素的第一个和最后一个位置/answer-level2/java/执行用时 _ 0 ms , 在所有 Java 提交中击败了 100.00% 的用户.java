### 解题思路
二分查找目标元素
找到目标元素后再向前 向后探索

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res = {-1, -1};
        int left = 0;
        int right = nums.length - 1;
        int mid;
        if (nums.length == 0 || nums[left] > target || nums[right] < target){
            return res;
        }
        while (left <= right){
            mid = (left + right) / 2;
            if (nums[mid] == target){
                int i = 1, j = 1;
                while (mid - i >= 0 && nums[mid - i] == target){
                    i++;
                }

                while (mid + j < nums.length && nums[mid + j] == target){
                    j++;
                }
                res[0] = mid - i + 1;
                res[1] = mid + j - 1;
                break;
            }else if (nums[mid] < target){
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }

        return res;
    }
}
```