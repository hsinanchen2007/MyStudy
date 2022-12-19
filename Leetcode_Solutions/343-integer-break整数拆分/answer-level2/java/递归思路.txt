解题思路：
f(2) = 1 * 1
f(3) = 1 * 2
f(4) = 2 * 2
f(5) = 2 * 3
f(6) = 3 * 3
f(7) = 3 * 4
f(8) = 3 * 3 * 2
f(9) = 3 * 3 * 3
f(10) = 3 * 3 * 4
f(11) = 3 * 3 * 3 * 2
可以发现对于 n > 7
有f(n) = 3 * f(n - 3)```
public int integerBreak(int n) {
        if (n <= 3) return n - 1;
        if (n == 4) return 4;
        if (n <= 7) return 3 * (n - 3);
        int sum = 1;
        while (n > 7) {
            sum *= 3;
            n -= 3;
        }
        sum *= integerBreak(n);
        return sum;
    }
```
