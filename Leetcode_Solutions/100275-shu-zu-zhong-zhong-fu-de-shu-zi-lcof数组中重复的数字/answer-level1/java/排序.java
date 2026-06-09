### 解题思路
用自带排序，便利数组 凡是下一个数字与当前数字相等， 就返回

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
         Arrays.sort(nums);
         for( int i =0; i < nums.length; i++){
             if( nums[i] == nums[i+1]){
                 return nums[i];
             }
         }
         return -1;
    }
}
```