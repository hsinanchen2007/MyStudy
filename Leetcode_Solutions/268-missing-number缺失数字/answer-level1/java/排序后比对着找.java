### 解题思路
排序后比对着找

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        Arrays.sort(nums);
        int index = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != index++) 
            return --index;
        }
        return index;
    }
}
```