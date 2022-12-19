### 解题思路
看当前数是否是好数，再递归调用计算rotatedDigits(N-1)。
至于判断当前数，主要是看每一位是否都是旋转数0/1/2/5/6/8/9，并且不能都是0/1/8。

### 代码

```java
class Solution {
    public int rotatedDigits(int N) {
        if (N == 1) return 0;
        boolean isGood = true;
        boolean isAll018 = true;
        int tmp = N;
        do {
            int remainder = tmp % 10;
            if ((remainder == 3) || (remainder == 4) || (remainder == 7)) {
                isGood = false;
                break;
            } else if ((remainder == 2) || (remainder == 5) || (remainder == 6) || (remainder == 9)) {
                isAll018 = false;
            };
            tmp = tmp / 10;
        } while (tmp > 0);
        return ((isGood && !isAll018) ? 1 : 0) + rotatedDigits(N - 1);
    };
}
```