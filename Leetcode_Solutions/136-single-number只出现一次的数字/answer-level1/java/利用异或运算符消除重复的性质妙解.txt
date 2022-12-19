### 解题思路
A^A^B^C^C=B

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
          int x = 0;
        for (int i = 0; i < nums.length; i++) {
            x = x ^ nums[i];
        }
        return x;
    }
}
```