### 解题思路
(num & 0xaaaaaaaa) >>> 1)保留偶数位，并左移。(num & 0x55555555) << 1保留奇数位，并右移。最后用|将两者重新组合在一起。

### 代码

```java
class Solution {
    public int exchangeBits(int num) {
        int n=0;
        n = ((num & 0xaaaaaaaa) >>> 1) | ((num & 0x55555555) << 1);
        return n;
    }
}
```