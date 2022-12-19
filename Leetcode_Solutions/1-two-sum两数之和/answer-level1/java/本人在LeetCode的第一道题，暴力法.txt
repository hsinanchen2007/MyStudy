### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
  for(int i=0;i<nums.length-1;i++){
      for(int j=i+1;j<nums.length;j++){
          if(nums[j]==target-nums[i]){
          return new int[]{i,j};
      }
      }
  }
throw new IllegalArgumentException("No two sum solution"); }
}
```