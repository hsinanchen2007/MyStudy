# 效率：
| $k$ | 时间效率 | 空间效率 |
| :-: | :-: | :-: |
| $k<9$ | $O(1)$ | $O(1)$ |
| $k\geqslant 9$ | $\leqslant O(min(k^2, mn))$ | $O(1)$ |
实际上系数是很小的，比DFS之类的小很多，**循环次数**的一个上界($k\geqslant 9$)为
## $min(\frac{(k-7)^2}{2},\frac{mn}{100})$

# 思路：
一个大的方向是把这些 $1\times 1$ 的格子划分为 $10\times 10$ 的块，事实上，每个块的性质都是相同的，所以可以把同样的操作在不同的块上进行，只需要改变参数就行。

在一个块内，一个 $k$ 值可以确定一条**斜线**（如果有的话），这条斜线可以把满足要求的格子和不满足要求的格子分开，而满足要求的格子又可以用若干个**等差数列求和**的式子来表示。

在块外，可以发现从一个块穿越到另一个块所需要的条件也是**斜线**分布的。我们假设左上角是 $(0,0)$ ，这个 $\frac{1}{4}$ 平面是向右下方生长的，第一个块的第一行是从 $(0,0)$ 到 $(0,9)$ ，坐标和从 $0$ 到 $9$ ，再向右移一格时 $(0,10)$ ，坐标和为 $1$ ，所以从左上角为 $(0,0)$ 的块穿越到左上角为 $(0,10)$ 的块需要 $k\geqslant 9$ ，从左上角为 $(0,10)$ 的块穿越到左上角为 $(0,20)$ 的块需要 $k\geqslant 10$ ；同理，从左上角为 $(0,0)$ 的块穿越到左上角为 $(10,0)$ 的块需要 $k\geqslant 9$ ，从左上角为 $(10,0)$ 的块穿越到左上角为 $(20,0)$ 的块需要 $k\geqslant 10$ 。

根据这个原则就可以设计代码。

# 代码：
```
class Solution {
public:
    int movingCount(int m, int n, int k) {
        int sum = 0;
        int m2 = m / 10, m1 = m % 10;
        int n2 = n / 10, n1 = n % 10;
        if(k < 9) {
            if (0 < m2 && 0 < n2) {
                sum += simpleCount(10, 10, k);
            } else if (0 < m2) {
                sum += simpleCount(10, n1, k);
            } else if (0 < n2) {
                sum += simpleCount(m1, 10, k);
            } else {
                sum += simpleCount(m1, n1, k);
            }
            return sum;
        }
        // k >= 9
        for (int i = 0; i < m2 + 1 && i <= k - 8; i++) {
            for (int j = 0; j < n2 + 1 && j <= k - 8 - i; j++) {
                if (i < m2 && j < n2) {
                    sum += simpleCount(10, 10, k - i - j);
                } else if (i < m2) {
                    sum += simpleCount(10, n1, k - i - j);
                } else if (j < n2) {
                    sum += simpleCount(m1, 10, k - i - j);
                } else {
                    sum += simpleCount(m1, n1, k - i - j);
                }
            }
        }
        return sum;
    }
private:
    // 等差数列求和
    int multiply(int n) {
        if (n < 1)
            return 0;
        else
            return (n + 1) * n / 2;
    }
    // 处理10x10的块
    int simpleCount(int m, int n, int k) {
        return multiply(k + 1) - multiply(k + 1 - m) - multiply(k + 1 - n) +
               multiply(k + 1 - m - n);
    }
};
```
