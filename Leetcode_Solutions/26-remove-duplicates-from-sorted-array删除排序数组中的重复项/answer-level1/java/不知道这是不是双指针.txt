### 解题思路
思路是直接遍历判断相邻的两个数是否一样，如果不一样，将后面的数放在j+1位置，第一个数已经放在j=0位置不用动，因为j是从0开始，所以返回的长度要加上1.

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int j=0;
        for (int i=0;i<nums.length-1;i++){
            if(nums[i]!=nums[i+1]){
                j=j+1;
                nums[j]=nums[i+1];  
            }
        }
        return j+1;     
    }
}
```