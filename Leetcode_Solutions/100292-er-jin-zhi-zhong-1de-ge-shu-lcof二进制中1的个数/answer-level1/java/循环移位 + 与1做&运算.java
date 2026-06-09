### 解题思路
int类型二进制为32bit，依次右移 0 ～ 31位即可

### 代码

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        
        int bitCount = 0;
        int i = 32;
        while (i > 0) {
            bitCount += ((n >> (32 - i--)) & 1);
        }

        return bitCount;
    }
}
```