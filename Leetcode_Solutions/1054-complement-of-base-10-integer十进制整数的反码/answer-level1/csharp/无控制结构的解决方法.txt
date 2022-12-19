```
public class Solution {
    public int BitwiseComplement(int N) {
        int mask = N | 1;
        mask |= mask >> 1;
        mask |= mask >> 2;
        mask |= mask >> 4;
        mask |= mask >> 8;
        mask |= mask >> 16;
        return N ^ mask;
    }
}
```