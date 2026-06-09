### 解题思路
知识面太浅，只能想到暴力法

### 代码
第一遍写概念，使用等不是很清晰，很多冗余。
```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int len=nums.length;
        int sum=0;
        for(int i=0;i<len;i++)
            for(int j=0;j<len;j++){
                if(i==j) continue ;
                sum=nums[i]+nums[j];
                if(sum==target){
                return new int []{i,j};
                }    
            }
throw new IllegalArgumentException("No two sum solution");//不可或缺
    }
}
```
暴力法改进
```Java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int len=nums.length;
        for(int i=0;i<len;i++)
            for(int j=i+1;j<len;j++){
                if(nums[i]+nums[j]==target){
                return new int []{i,j};           
                }    
            }
throw new IllegalArgumentException("No two sum solution");
    }
}
```
