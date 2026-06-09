### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        if( nums.length <= 0 ) return -1;
        int left = 0 , mid = 0;
        int right = nums.length-1;
        while (left < right){
            mid = (left+right)/2;
            if (nums[mid] < target){
                //如果中间的数小于target，会有两种情况发生可能位于左侧或者右侧。
                //左侧条件：左侧只能是无序 nums[mid]<nums[left]
                //右侧条件：1.如果右侧有序则只能满足nums[right]>target。2.右侧无序则必在右侧，因为nums[mid]>target了。

                if (nums[mid] < nums[left]){ //左侧无序
                    if (nums[right] < target)  //右侧必然有序，当target > nums[right]时，target必在左侧；
                        right = mid;
                    else   //当右侧有序的情况下，而且target < nums[right]则target必在右侧；
                        left = mid;
                }else if ( nums[left] < nums[mid] ){
                    //当左侧有序，则必然在右侧。
                    left = mid;
                }else{
                    if (target == nums[right]){
                        mid = right;
                        break;
                    }else
                        break;

                }


            }else if ( target < nums[mid] ){
                //如果中间的数大于target，也可能在左侧或者右侧
                if ( nums[left] < nums[mid] ) //左侧有序的情况下
                {
                    if (target < nums[left]) //左侧全部元素都大于target，则必在右侧
                        left = mid;
                    else
                        right = mid;
                }else if (nums[left] > nums[mid]){ // 左侧无序，右侧必有序，则必在左侧
                    right = mid;
                }else {
                    if (target == nums[right]){
                        mid = right;
                        break;
                    }else
                        break;
                }
            }else break;
        }
        return nums[mid]==target?mid:-1;
    }
}
```