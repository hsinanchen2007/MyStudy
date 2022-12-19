### 解题思路
此处撰写解题思路

### 代码
**二分查找**
```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        if(nums.length == 0){
            return 0;
        }
        int mid = nums.length/2;
        int left = 0;
        int right = nums.length-1;
        while(true){
            if(target > nums[mid]){
                left = mid + 1;
                if(left >= right + 1){
                    return left;
                }
                mid = (left + right)/2;
            }
            else if(target < nums[mid]){
                right = mid - 1;
                if(left >= right + 1){
                    if(right < 0){
                        return 0;
                    }
                    return right+1;
                }
                mid = (left + right)/2;
            }
            else{
                return mid;
            }
        }
    }
}
```

**普通遍历**
```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        for(int i = 0; i < nums.length; i++){
            if(nums[i] >= target){
                return i;
            }
        }
        return nums.length;
    }
}
```