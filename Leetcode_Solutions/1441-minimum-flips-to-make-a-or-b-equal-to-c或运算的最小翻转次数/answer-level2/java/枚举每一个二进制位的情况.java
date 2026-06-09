
思路：题目已经展示了二进制逐个比对的形式，看它的竖式加法就可以想到思路，只要枚举每一位可能出现的情况即可。


**参考代码**：

```Java []
public class Solution {

    // 或运算的特点是：
    // 1、两个数位都是 0，才为 0；
    // 2、只要有一个数位是 1 ，就是 1。

    public int minFlips(int a, int b, int c) {
        // 特判
        if ((a | b) == c) {
            return 0;
        }

        int res = 0;
        for (int i = 0; i < 32; i++) {
            // 枚举：
            // 1、1 or 1 = 1，如果遇到 0，翻转 2 次；
            // 2、1 or 0 = 1，如果遇到 0，翻转 1 次；
            // 3、0 or 1 = 1，如果遇到 0，翻转 1 次；
            // 4、0 or 0 = 0，如果遇到 1，翻转 1 次；

            int maskA = a & 1;
            int maskB = b & 1;
            int maskC = c & 1;

            if (maskA == 1 && maskB == 1 && maskC == 0) {
                res += 2;
            } else if (maskA == 1 && maskB == 0 && maskC == 0) {
                res += 1;
            } else if (maskA == 0 && maskB == 1 && maskC == 0) {
                res += 1;
            } else if (maskA == 0 && maskB == 0 && maskC == 1) {
                res += 1;
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return res;
    }
}
```
