### 解题思路
边界条件
$$F(n=0)=0$$
$$F(n<10)=1$$

$n\geq 10$时，我们可以将$n$表示为$XY$的形式，其中$Y$是一个一位数。

从而，我们可以将$[0,n]$的整数分为$[0,(X-1)9]$和$[X0,XY]$两部分。

$[X0,XY]$这部分包含1的个数等于$X$中包含1的个数乘上$Y+1$，同时如果$Y\geq 1$，还要再加上1。

$[0,(X-1)9]$这部分可以看成10个$[0,X-1]$，再加上$X$个1。

从而就有了下面的表达式

$$F(n)=cnt(n/10)\cdot(n\%10+1)+(n\%10\neq0)+10F(n/10-1)+n/10$$

### 代码

```cpp
class Solution {
    int count(int n) {
        int ans = 0;
        while (n > 0) {
            if (n % 10 == 1)
                ans++;
            n /= 10;
        }
        return ans;
    }
public:
    int countDigitOne(int n) {
        if (n == 0)
            return 0;
        if (n < 10)
            return 1;
        int ans = n % 10 >= 1;
        ans += count(n / 10) * (n % 10 + 1) + countDigitOne(n / 10 - 1) * 10 + n / 10;
        return ans;
    }
};
```