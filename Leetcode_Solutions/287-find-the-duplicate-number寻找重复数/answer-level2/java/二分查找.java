### 解题思路
利用二分查找， 根据数字的范围[1,n]进行二分

### 代码

```java
class Solution {
    public int findDuplicate(int[] nums) {
         
         int start = 1, end = nums.length - 1;
         while (start < end ){
             int middle = start + ((end - start) >> 1);
             if (isDul(nums,start, middle)){
                 end = middle;
             }
             else start = middle + 1;
         }
         return start;//由于必然有重复值，直接返回start即可；
    }

    private boolean isDul(int[] nums, int start, int end){//判断 [start, end]区间是否有重复值
        int count = 0;
        for (int i = 0; i < nums.length; i++){
            if (nums[i] >= start && nums[i] <= end)
                count++;
        }
        return count > end - start + 1? true : false;
    }

}
```