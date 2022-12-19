### 解题思路
由于需要统计某个数字 target 在数组中的次数，所以只需要知道 target 在数组中第一次出现的位置和最后一次出现的位置即可，下面利用二分查找分别进行讨论：

- 1.对于 target **第一次出现的位置**，首先拿中间的数和 target 比较：
    - 1.1 如果中间的数大于 target，则说明 target 在数组的前半段。
    - 1.2 如果中间的数小于 target，则说明 target 在数组的后半段。
    - 1.3 如果中间的数等于 target，还需要判断这个数字是不是第一个 target：
        - 1.3.1 如果中间数字的前面一个数字不是 target，则说明当前中间的数字就是第一个 target；
        - 1.3.2 如果中间数字的前面一个数字是 target，则还要在左侧继续寻找。
- 2.对于 target **最后一次出现的位置**，也是拿中间的数和 target 比较：
    - 2.1 如果中间的数大于 target，则说明 target 在数组的前半段。
    - 2.2 如果中间的数小于 target，则说明 target 在数组的后半段。
    - 2.3 如果中间的数等于 target，还得判断这个数字是不是最后一个 target：
        - 2.3.1 如果中间数字的后面一个数字不是 target，则说明当前中间的数字就是最后一个 target；
        - 2.3.2 如果中间数字的后面一个数字是 target，则还要在右侧继续寻找。

### 代码
```java
class Solution {
    public int search(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        
        int res = 0;
        // target 在数组中第一次出现的位置
        int firstIndex = getFirst(nums, target, 0, nums.length - 1);
        // target 在数组中最后一次出现的位置
        int lastIndex = getLast(nums, target, 0, nums.length - 1);
        // 不越界的话，则返回等于 terget 的范围的长度
        if (firstIndex > -1 && lastIndex > -1) {
            res = lastIndex - firstIndex + 1;
        }
        return res;
    }
    
    // 获得 target 在数组中第一次出现的位置
    private int getFirst(int[] nums, int target, int left, int right) {
        if (left > right) {
            return -1;
        }
        
        int middleIndex = left + ((right - left) >> 1);
        int middleData = nums[middleIndex];
        
        // 情况 1.3
        if (middleData == target) {
            // 情况 1.3.1
            if ((middleIndex > 0 && nums[middleIndex - 1] != target) 
                || middleIndex == 0) {
                return middleIndex;
            // 情况 1.3.2
            } else {
                right = middleIndex - 1;
            }
        // 情况 1.1
        } else if (middleData > target) {
            right = middleIndex - 1;
        // 情况 1.2
        } else if (middleData < target) {
            left = middleIndex + 1;
        }
        return getFirst(nums, target, left, right);
    }
    
    // 获得 target 在数组中最后一次出现的位置
    private int getLast(int[] nums, int target, int left, int right) {
        if (left > right) {
            return -1;
        }
        
        int middleIndex = left + ((right - left) >> 1);
        int middleData = nums[middleIndex];
        
        // 情况 2.3
        if (middleData == target) {
            // 情况 2.3.1
            if ((middleIndex < right && nums[middleIndex + 1] != target) 
                || middleIndex == right) {
                return middleIndex;
            // 情况 2.3.2
            } else {
                left = middleIndex + 1;
            }
        // 情况 2.1
        } else if (middleData > target) {
            right = middleIndex - 1;
        // 情况 2.2
        } else if (middleData < target) {
            left = middleIndex + 1;
        }
        return getLast(nums, target, left, right);
    }
}
```
### 全部题解
《剑指Offer》的全部题解与 LeetCode 的部分题解在此下方，其中还包含**基础算法**与**进阶算法**，欢迎查看~
[LeetCode、SwordToOffer and other algorithms in Java.](https://github.com/dyfloveslife/LeetCodeAndSwordToOffer)