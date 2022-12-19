### 解题思路
有序数组

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        for(int i=0;i<=nums.length-1;i++)
            if(nums[i] != i) return i;
        return nums.length;
    }
}
```