### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int arrayPairSum(int[] nums) {
        int count=0;
        Arrays.sort(nums);
       for(int i=0;i<nums.length;i+=2)
       count+=nums[i];
       return count;
    }
}
```