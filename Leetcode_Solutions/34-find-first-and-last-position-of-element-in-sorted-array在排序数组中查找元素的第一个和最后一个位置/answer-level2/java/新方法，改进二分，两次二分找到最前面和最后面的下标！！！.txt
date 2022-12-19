### 解题思路
改进二分，比如要找4，就找3.5和4.5的下标位置（虽然不存在）。二分返回的下标是前面一个整数的下标，比如3.5，返回的是第一个大于3的整数的下标，4.5返回4前面第一个大于4整数的下标（这个大家在纸上画一画）。
例：
```java
nums = [5,7,7,8,8,10], target = 8
left = binarySearch(nums, 7.5); //返回第一个8的下标
right = binarySearch(nums, 8.5); //返回10的下标

new int[]{left, right - 1};

```

### 代码

```java
class Solution {

    public int binarySearch(int[] nums, double target) {
        int L = 0, R = nums.length - 1;
        while(L <= R) {
            int mid = (L + R) / 2;
            if(nums[mid] > target) {
                R = mid - 1;
            } else {
                
                L = mid + 1;
            }
        }
        return L;
    }

    public int[] searchRange(int[] nums, int target) {
        if(nums == null || nums.length == 0) return new int[]{-1, -1};
        int left = binarySearch(nums, target - 0.5);
        int right = binarySearch(nums, target + 0.5); 
        if(left == right) {
            return new int[]{-1, -1};
        }
        return new int[]{left, right - 1};
    }
}
```