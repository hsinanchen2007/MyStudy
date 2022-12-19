### 解题思路
位运算即可完成

### 代码

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        // 
        int count = 0;
        while (n != 0) {
            count += n & 1;
            n = n >>>1;
        }
        return count;
    }
}
```