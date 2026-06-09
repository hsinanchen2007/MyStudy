### 代码

```java
class Solution {
    public int binaryGap(int n) {
        int pos = 32;
        int last;
        int j = 1;
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            if ((n & j) != 0) {
                last = pos;
                pos = i;
                ans = Math.max(pos - last, ans);
            }
            j <<= 1;
        }
        return ans;
    }
}
```