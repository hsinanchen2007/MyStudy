### 解题思路
将数组不断分成两部分，然后判断target在哪一部分。
问题1：前半部分排好序了，还是后半部分排好序了？这个问题的解法是：如果前一半的第一个小于后一半的第一个，则认为前一半排好序（另一半回环）；反之亦然。
问题2：如何判断target在哪一部分？这个问题的解法是：如果target不在排好序的部分里（通过比较排好序的第一个元素和最后一个元素是否小于及大于目标值），就必定在有回环的那部分里。
问题3：如何达到log n的效率，将target在的部分继续用二分法不断拆分。

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        if (nums == null || nums.length == 0){
            return - 1;
        }
        return searchHelper(nums, 0, nums.length - 1, target);
    }

    public int searchHelper(int[] nums, int low, int high, int target){
        int med = low + (high - low) / 2 + 1;
        if (target == nums[low]){
            return low;
        }
        if (target == nums[high]){
            return high;
        }

        if (low == high){
            return - 1;
        }
        if (nums[low] < nums[med]){
            // 检查是前一半排序好了，还是后一半排序好了
            // 如果前一半的第一个小于后一半的第一个，则认为是前一半已排好序；
            // if (first_half[0] < second_half[0]) ==> first_half sorted, no recursion
            if (target > nums[med - 1] || target < nums[low]){
                // 在另一半
                return searchHelper(nums, med, high, target);
            } else {
                return searchHelper(nums, low, med-1, target);
            }
        } else {
            // 如果前一半的第一个大于后一半的第一个，则认为是后一半已排好序。
            // if (first_half[0] > second_half[0]) ==> second_half sorted, no recursion
            if (target > nums[high] || target < nums[med]){
                return searchHelper(nums, low, med-1, target);
            } else {
                return searchHelper(nums, med, high, target);
            }
        }
    }
}
```