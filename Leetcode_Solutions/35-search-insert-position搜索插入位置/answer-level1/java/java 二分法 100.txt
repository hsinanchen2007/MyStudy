### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
         if(nums == null || nums.length ==0){
             return 0;
         }
         int left = 0 , right = nums.length-1;
         while(left+1 <right){
             int mid = left +(right - left )/2;
             if(nums[mid] > target){
                 right = mid;
             }
             else if(nums[mid] < target){
             left = mid;
             }else{
                 return mid;
             }
         }

         if(nums[left] >= target){
               return left;    //  [2,3]找1
         }

        else if( nums[ right]< target) 
        return right+1;     //[1,2] 找 3

        else return right;       //[ 2,4]找3

    }
}
```