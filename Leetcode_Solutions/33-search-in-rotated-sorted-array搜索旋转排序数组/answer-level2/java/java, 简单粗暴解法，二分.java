### 解题思路
根据数组已经排序，但是自旋的特点，如果，具体分析可以看点赞最高的。
### 代码

```java
class Solution {
    
    public int search(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
           return -1;
       }
      int left = 0;
      int right = nums.length - 1;
      int mid ;
      while (left <= right){
            mid = (left + right)/2;
            if (nums[mid] == target)
                return mid;
            //这个是为了处理，假如存在重复值, 小于说明left--mid 是有序的
            if (nums[left] <= nums[mid]){
                if (target >= nums[left] && target <= nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }else { // left-mid包含自旋，所以mid-》len-1是升序排列的, 由于mid已经过了自旋点，所以如果 target 属于 mid-len-1
                    //则 肯定大于 nums[mid], 小于nums[0], 因为nums[0]是自旋点之后的数据肯定大于自旋点之前的数据
                if (target >= nums[mid] && target < nums[0])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
      }
     return  -1;
    }
}
```