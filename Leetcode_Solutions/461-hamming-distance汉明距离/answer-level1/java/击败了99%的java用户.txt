[更多leetcode题解参考此处](https://github.com/reedfan/leetcode/tree/master/src/main/java/leetcode)
```
public int hammingDistance(int x, int y) {
        int cnt = 0;
        while (x != 0 || y != 0) {
            if ((x & 1) != (y & 1)) {
                cnt++;
            }
            x >>= 1;
            y >>= 1;
        }
        return cnt;
    }
```
