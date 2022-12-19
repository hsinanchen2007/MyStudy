### 解题思路
感觉其他的题解讲的有点复杂了，其实就是把每一位移到最后，通过&1把前面几位置为0，再左移到相应位置就行

### 代码

```java
public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res += ((n >> i) & 1) << (31 - i);
        }
        return res;
    }
}
```