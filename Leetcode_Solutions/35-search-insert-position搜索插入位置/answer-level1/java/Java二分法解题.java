### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int start = 0,end = nums.length - 1;
        int mid;
        while(start <= end){
            mid = start + (end - start)/2;
            if(nums[mid] < target){
                start = mid + 1;
            }else if(nums[mid] > target){
                end = mid - 1;
            }else{
                return mid;
            }
        }
        return start;
    }
}
```