### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minMoves(int[] nums) {
        int count=0,min=nums[0];
       for(int i=0;i<nums.length;i++){
           count+=nums[i];
           if(nums[i]<min)
           min=nums[i];
       }
       return  count-min*nums.length;
    }
}
```