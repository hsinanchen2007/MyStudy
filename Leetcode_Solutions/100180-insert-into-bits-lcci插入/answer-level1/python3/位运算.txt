解题思路：先用0覆盖i-j之间bit位置，再将M左移i位合并
首先，用0覆盖i-j之间你得先得到(j - i +1)bit长度的0且32位其他位都以为1，用$2^{j - i + 1} - 1$可以得到(j - i + 1)bit长度的1，再将其位反即可获得(j - i +1)bit长度的0（这里使用Python需要注意一下，Python的整数长度不是32，且大部分计算语言整数的首位都是表示正负，位反会变为负数，如0b1100100(100), -0b1100101(~100)，这里我使用0xFFFFFFFF掩码进行异或操作进行位反）
最后再将N上位置覆盖为0，再与M合并
```python3
class Solution:
    def insertBits(self, N: int, M: int, i: int, j: int) -> int:
        temp = (1 << (j - i +1)) - 1
        mask = 0xFFFFFFFF
        temp = mask ^ (temp << i)
        M <<= i
        return (N & temp) | M
```
![2020-02-26 13-51-23 的屏幕截图.png](https://pic.leetcode-cn.com/dee07a349f38ca10c20d796e8f827b89cff0048d5c15a893a099fe6f288af9f6-2020-02-26%2013-51-23%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

