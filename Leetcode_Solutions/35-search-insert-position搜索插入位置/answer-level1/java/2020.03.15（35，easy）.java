### 解题思路
本题使用**二分查找**的思想

通过定义中间位置mid，将数组划分为左右两端，每次查找都是一半一半，时间复杂度为O(logn)

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        if(nums == null || nums.length == 0){
            return 0;
        }
        while(left <= right){
            int mid = left + ( right - left ) / 2;//划分左右两侧
            if(target == nums[mid]){
                return mid;
            } 
            if(target > nums[mid]){
                left = mid + 1;
            }else{
                right = mid - 1; 
            }
        }
        return left;
    }
}
```