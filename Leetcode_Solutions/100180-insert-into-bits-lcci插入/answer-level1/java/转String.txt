# 代码
```java
class Solution {
    public int insertBits(int N, int M, int i, int j) {
        StringBuilder sb_N = new StringBuilder(Integer.toBinaryString(N)),
                sb_M = new StringBuilder(Integer.toBinaryString(M));
        int remain = 32 - sb_N.length();
        while (--remain > -1) sb_N.insert(0, '0');
        remain = j - i + 1 - sb_M.length();
        while (--remain > -1) sb_M.insert(0, '0');
        sb_N.replace(31 - j, 32 - i, sb_M.toString());
        return Integer.parseInt(sb_N.toString(), 2);
    }
}
```
