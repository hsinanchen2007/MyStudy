#### 解题思路：
对于数字的末位，直接取余就可以了，对于数字的首位，我们可以这么算。
首先用一个变量记录数字的最高位，
比如 $12321$，可以标记 `help` 为 $10000$，
第一个末位为 $1$，第一个首位为 `12321/10000=1`，
接下来我们需要计算 $232$ 是否为回文，怎么计算呢？
我们需要去掉首位和末位。
可以采用 `x % help / 10` 的方式
`12321%10000==2321` 可以将最高位去掉，然后 `2321/10==232` 可以将最低为去掉。
最后不要忘记将 `help/100`。
#### 代码：
```Java [-Java]
 public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int help = 1;
        int tmp = x;
        while (tmp >= 10) {
            help *= 10;
            tmp /= 10;
        }
        while (x != 0) {
            if (x % 10 != x / help) {
                return false;
            }
            x = x % help / 10;
            help /= 100;
        }
        return true;
    }
```
