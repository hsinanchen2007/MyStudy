### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        if( nums.length <= 0 ) return -1;
        if( nums.length == 1 ){
            if (target == nums[0])
                return 0;
            else if (target < nums[0])
                return 0;
            else
                return 1;
        }
        int left = 0 , mid = 0;
        int right = nums.length-1;
        while (left < right){
            mid = (left+right)/2;
            if (nums[mid] < target){
                //target在右侧
                if (nums[left] == nums[mid]){
                    //只留下了两个数
                    if (target == nums[right])
                        return right;
                    else if (target < nums[right])
                        return right;
                    else
                        return right+1;
                }else//还有至少三个数
                    left = mid;
            }else if (target < nums[mid]){
                //target在左侧
                if (nums[left] == nums[mid]){
                    //只留下了两个数
                    if (target == nums[right])
                        return right;
                    else
                        return left;
                }else//还有至少三个数
                    right = mid;
            }else
                return mid;
        }
        return 0;
    }
}
```