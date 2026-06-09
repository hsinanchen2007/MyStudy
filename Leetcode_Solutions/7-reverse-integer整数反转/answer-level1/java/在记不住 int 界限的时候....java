### 解题思路
在不知道 int 界限的时候。。。

### 代码

```java
class Solution {
    public int reverse(int x) {
        // 计算有符号 int 的界限
        int s = -1;
        for (int i = 1; i <= 31; i++) {
            s = s * 2;
        }
        long negativeS = (int) s;
        s = 0 - (s+1);
        long positiveS = (int) s;
        // x 进行翻转
        long X = (int) x;
        long Y = 0;
        while (X != 0) {
            Y = Y * 10 + (X % 10);
            X /= 10;
        }
        if (Y > positiveS || Y < negativeS) {
            return 0;
        }
        else {
            return (int) Y;
        }
    }
}
```