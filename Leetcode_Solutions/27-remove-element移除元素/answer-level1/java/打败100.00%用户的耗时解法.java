### 解题思路
如果不是目标值，保留并计数；否则，跳过。

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int numLen = nums.length;
        if (numLen == 0) {
            return numLen;
        }
        int count = 0;
        for (int i = 0; i < numLen; i++) {
            if (nums[i] != val) {
                nums[count++] = nums[i];
            } 
        }
        return count;
    }
}
```