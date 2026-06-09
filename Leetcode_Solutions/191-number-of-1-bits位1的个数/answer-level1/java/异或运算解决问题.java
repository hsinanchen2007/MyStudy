### 解题思路
计算n与0的异或，即可知道有多少个1.

### 代码

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        return Integer.bitCount(n^0);
    }
}
```