这里提供一种非枚举思路
依次从个位往高位判断来生成其中的一个子数：
    1. 若此位为1，则子数该位取2就一定能保证两个子数该位不为0；否则取1即可；
    2. 依次往高位遍历。若遇到最后一位（即x小于10），直接中断即可。
```
class Solution {
    public int[] getNoZeroIntegers(int n) {
        int a = n < 10 ? 1 : 0;
        int digit = 1;
        int x = n;
        while (x > 0) {
            if (x < 10) {
                break;
            }
            int delta = x % 10 != 1 ? 1 : 2;
            a += delta * digit;
            x -= delta;
            x /= 10;
            digit *= 10;
        }
        return new int[]{a, n - a};
    }
}
```
