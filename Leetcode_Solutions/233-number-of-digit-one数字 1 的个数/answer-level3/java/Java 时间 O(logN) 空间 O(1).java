### 解题思路
把一个数分成两部分 left和right 每次从left末位取值判断这位贡献了多少1。left初始为n 每次循环截掉末位 累加计算right, left为0时结束。
时间复杂度取决于数的位数=log_10 n = logn。
当运行到十位时的例子：此时mul (multipler) = 10
- 207  left=20 digit=0 left/=10后为2 right=7还未更新 十位贡献2 * 10 2个full streak 10...19 110...119 此时该位贡献1数完全取决于left。 计数完毕后更新right+=0 * 10 = 7 mul*=10 = 100
- 217  left=21 digit=1 left/=10后为2 right=7还未更新 十位贡献2 * 10 + 8 (右边为0-7) 10...19 110...119  210...218 2个full streak 1个由右边产生的partial streak。 此时该位贡献1数同时取决left和right。 计数完毕后更新right+=1 * 10=17 mul*=10 = 100
- 227  left=22 digit=2>1 left/=10后为2 right=7还未更新 十位贡献3 * 10  3个固定的full streak 10...19 110...119 210...219 此时该位贡献1数完全取决于left。 计数完毕后更新right+=2 * 10=27 mul*=10 = 100

### 代码

```java
class Solution {
    public int countDigitOne(int n) {
        if (n <= 0) return 0;
        int cnt = 0, mul = 1, left = n, right = 0;
        while (left != 0) {
            int digit = left % 10;
            left /= 10;
            if (digit == 0) cnt += left * mul;
            else if (digit == 1) cnt += left * mul + right + 1;
            else cnt += (left + 1) * mul;
            right += digit * mul;
            mul *= 10;
        }
        return cnt;
    }
}
```