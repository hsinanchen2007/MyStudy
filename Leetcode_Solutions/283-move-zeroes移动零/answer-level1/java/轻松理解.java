```java
class Solution {
    public void moveZeroes(int[] nums) {
        int left = 0;
        //先将不是0的数字放到前面
        for(int i = 0 ;i<nums.length;i++){
            if(nums[i]!=0){
                nums[left] = nums[i];
                left++;
            }
        }
        //将剩下的空间置0
        for(int j = left;j<nums.length;j++){
            nums[j]= 0;
        }
    }
}
```