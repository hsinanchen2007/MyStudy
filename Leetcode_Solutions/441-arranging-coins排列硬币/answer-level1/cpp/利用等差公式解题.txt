## 推导过程
等差公式的和公式为:
$s_n = na_1 + \frac{n(n-1)}{2}d$
其中$$n是数列的个数，$a_1$是数列的初始值，$d$是数列的公差。
在这条题目中, 由于参数名字和等差公式的名字有冲突，我们将它重命名为sum, $a_1 = 1$,$d=1$ 以下为推导过程。
$sum = n + \frac{n(n-1)}{2}$
两边乘以2并加上$\frac{1}{4}$，得
$2.sum + \frac{1}{4} = n^2 + n + \frac{1}{4}$
等式右部配方法，得
$2.sum+\frac{1}{4} = (n+\frac{1}{2})^2$
等式两边开方，得
$\sqrt{2.sum+\frac{1}{4}} = (n+\frac{1}{2})$
则答案
$n = \sqrt{2.sum+\frac{1}{4}} - \frac{1}{2}$
还要注意防止整数溢出:
$n = 2 * \sqrt{sum / 2+\frac{1}{16}} - \frac{1}{2}$
## C++程序
```cpp
class Solution {
public:
    int arrangeCoins(int n) {
        return (int)(2 * sqrt(n / 2.0 + 0.0625) - 0.5);
    }
};
```