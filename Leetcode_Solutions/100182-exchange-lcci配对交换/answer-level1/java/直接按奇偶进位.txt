很简单的进位问题，只是不要搞错了什么时候该进位。

```
class Solution {
    public int exchangeBits(int num) {
        int target = 0;
        if (num == 1) {
            return 2;
        }

        for (int i = 0; i < 32; i++) {
            if (i % 2 == 0) {
                // 偶数进位
                int count = ((1 << i ) & num) << 1;
                target += count;
            } else {
                target += ((1 << i) & num) >> 1;
            }
        }
        return target;
    }
}
```
