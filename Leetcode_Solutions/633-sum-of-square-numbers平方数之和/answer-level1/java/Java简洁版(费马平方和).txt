### 费马平方和版

- 引理1：*形如4k+3的自然数不能表示成2个整数的平方和*
- 引理2：*正整数n可被表示为两整数平方和的充要条件为n的一切形如4k+3形状的质因子的幂次均为偶数*
- 说 明：*引理2 是基于`费马平方和`的推论*
```java
class Solution {
    public boolean judgeSquareSum(int c) {
        // n % 2^n = n & 2^n-1
        if ((c & 3) == 3)
            return false;
        for (int i = 2; i * i <= c; i++) {
            // 求c的质因子
            if (c % i != 0)
                continue;
            // 质因子的幂次
            int count = 0;
            while (c % i == 0) {
                count++;
                c /= i;
            }
            // 引理2
            if ((i & 3) == 3 && (count & 1) == 1)
                return false;
        }
        // 此c非彼c
        return (c & 3) != 3;
    }
}
```

——————————————————————————————————————————————————
### 双指针版
```java
class Solution {
    public boolean judgeSquareSum(int c) {
        int i = 0;
        int j = Math.sqrt(c);
        while (i <= j) {
            int sum = i * i + j * j;
            if (sum == c)
                return true;
            if (sum > c)
                j--;        // sum > c : 整数 j 过大，导致 和 大于 整数 c
            else
                i++;        // sum < c : 整数 i 过小，导致 和 小于 整数 c
        }
    }
}
```
——————————————————————————————————————————————————
### 比较版
```java
class Solution {
    public boolean judgeSquareSum(int c) {
        for (int i = 0; i <= Math.sqrt(c); i++) {
            double sqrt = Math.sqrt(c - i * i);
            // 判断sqrt是否为一个整数
            if (sqrt == (int)sqrt)
                return true;
        }
        return false;
    }
}
```