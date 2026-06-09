### 解题思路 指数幂法
如何快速求幂？核心思想就是分治原理。求x=base^a，base是底数，a为指数幂，对base^a进行分治，即：
```
base^a = base^(a/2+a/2) = base^(a/2) * base^(a/2)                     a mode 2 = 0;
base^a = base^((a-1)/2+(a-1)/2) = base^((a-1)/2) * base^((a-1)/2)     a mode 2 = 1;
```
如此就能够通过将a分解成二进制，对其使用与&和右移>>操作了。
- 其它 ： 库函数法和手写幂函数法,
- 注意 ： INT_MIN 的绝对值因为比 INT_MAX 大1，无法进行直接取反操作，所以可以先移位后再取反，也可以强制转换为 unsigned int类型再取反
### 代码

```cpp
double myPow(double x, int n) {
    double m = 1;

    if (n == 0) {
        return 1;
    }

    // WARNing : abs(INT_MIN) 比 INT_MAX 大1，
    // 所以不能直接使用 n=-n
    if (n == INT_MIN) {
        // 将n右移一位，
        // 这样 n=-n 就不会出错
        n = n >> 1;
        // 因为n右移了一位，
        // 所以 x 需要翻倍
        x = x * x;

        // 这里也可以强制转换为 unsigned int类型进行取反
        // unsigned int a = (unsigned int)n;
    }

    // 当 n<0 时，需要将n取反、x取倒
    if (n < 0) {
        n = -n;
        x = 1 / x;
    }

    while (n != 0) {
        //a&1表示判断a的二进制最后一位是否为1
        if (n & 1) {
            //当位数为1时，乘底数
            m *= x;
        }

        //a每移位一次，base乘一倍
        x *= x;
        //右移或a/=2
        n = n >> 1;
    }

    return m;
}
```