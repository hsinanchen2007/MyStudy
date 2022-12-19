### 解题思路
首先肯定是通过二分查找的方式进行查找，根据左闭右开的原则：
当目标值等于mid时，直接返回mid
当目标值小于mid时，应该将right设置为mid；
当目标值大于mid时，应该将left设置为mid+1

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        //二分查找
        int left = 0;
        int right = nums.length;
        while(left < right){
            int mid = (left + right) / 2;
            if(target == nums[mid]) return mid;
            if(target < nums[mid]){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
}
```