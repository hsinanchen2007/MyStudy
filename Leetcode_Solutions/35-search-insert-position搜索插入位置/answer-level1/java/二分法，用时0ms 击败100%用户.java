### 解题思路
二分法查找，未找到时，返回最后一次二分查询的起始索引即可。

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
// 1.遍历法
        //  for (int i = 0; i < nums.length; i++){
        //      if (nums[i] == target || nums[i] > target ){
        //          return i;
        //      }
        //  }
        //  return nums[nums.length - 1] > target ? 0 : nums.length;
//2.二分查找法
        int lo = nums.length -1;
        int start = 0;
        int mid = 0;
        while (start <= lo){
                mid = start + (lo - start)/2;
                if(target > nums[mid])  start = mid  + 1;
                else if (target < nums[mid]) lo = mid -1;
                else return mid;
        }
           return start;
    }
}
```