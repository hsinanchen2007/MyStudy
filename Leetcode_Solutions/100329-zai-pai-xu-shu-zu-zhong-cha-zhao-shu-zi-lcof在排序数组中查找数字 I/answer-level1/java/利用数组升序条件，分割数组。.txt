### 解题思路
- 将数组分割
- 因为数组生效，利用数组中间下标上的值和目标值比较，如果目标值在高位区，从中间开始向后循环，直到数组内元素大于目标值跳出循环;
- 从数组的一半前一个下标开始向前循环直到存在相等则+1,再向前循环由于是升序数组则当存在第一个小于目标的数跳出循环。
### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        int count = 0;
        if(nums.length == 0){
            return count;
        }
        int mid = nums.length / 2;
        //如果数组中间位置下标上的值小于目标值那直接循环数组高位区
        //从数组的一半位置开始向后循环直到存在相等则+1,再向后循环由于是升序当存在一个大于目标值的数直接跳出循环
        if (target >= nums[mid]) {
            for (int i = mid; i < nums.length; i++) {
                if (target == nums[i]) {
                    count++;
                    continue;
                }
                if (target < nums[i]) {
                    break;
                }
            }
        }
        //此处不判断，数组中有可能2个在高区2个在低区
        //从数组的一半前一个下标开始向前循环直到存在相等则+1,再向前循环由于是升序数组则当存在第一个小于目标的数跳出循环。
        for (int i = mid - 1; i >= 0; i--) {
            if (target == nums[i]) {
                count++;
                continue;
            }
            if (target > nums[i]) {
                break;
            }
        }
        return count;
    }
}
```