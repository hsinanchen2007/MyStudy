### 解题思路


### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int size = nums.length*(nums.length+1)/2;
        int size2 = 0;
        for(int i = 0;i<nums.length;i++)
        {
            size2 = size2+nums[i];
        }
        return size-size2;
    }
}
```