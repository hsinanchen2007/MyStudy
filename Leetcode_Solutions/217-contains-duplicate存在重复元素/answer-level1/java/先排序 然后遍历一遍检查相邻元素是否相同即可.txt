### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
     Arrays.sort(nums);
     for(int i=0;i<nums.length-1;i++)
     {
         if(nums[i]==nums[i+1]) return true;
     }
     return false;
}
}
```