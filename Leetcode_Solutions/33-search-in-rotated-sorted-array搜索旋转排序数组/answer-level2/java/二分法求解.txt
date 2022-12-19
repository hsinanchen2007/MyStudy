### 解题思路
旋转数组在正常情况下可以分为两个有序数组，两个有序数组的范围不同，因此可以使用二分法。这里的二分法首先要做一次判断：判断二分之后的两个子数组到底哪个是有序的那个是无序的，如果目标数恰好在有序的子数组范围内，则将区间缩小到有序子数组，重新二分；如果在无序子数组范围内则将区间缩小到无序子数组，重新二分。循环在左右指针相等时退出，此时指针所指的数不一定等于目标数，需做一次判断。
旋转数组在极端情况下可能为一个有序数组，也可用上面的思路来解决。
执行用时0ms 内存消耗39.8MB

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        if(nums.length==0) return -1;
        int left = 0 ;
        int right = nums.length-1;
        int mid;
        while(left<right){
            //分割数组为[left,mid]和[mid+1,right]
            mid =(right+left)/2;
            //如果前一个数组有序
            if(nums[left]<=nums[mid]){
                //如果目标数在前一个数组的范围内
                if(target<=nums[mid] && target>=nums[left]){
                    right = mid;
                //如果目标数在后一个数组范围内
                }else{
                    left = mid+1;
                }
            //前一个数组无序，说明后一个数组一定是有序的
            }else{
                //如果目标数在后一个数组的范围内
                if(target>=nums[mid] && target<=nums[right]){
                    left = mid;
                //如果目标数在前一个数组的范围内
                }else{
                    right =mid-1;
                }
            }
        }
        //当循环结束需要判断是否找到的数与目标数相等
        return nums[left]==target?left:-1;
    }
}
```