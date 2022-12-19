# 随机大法好！
（大雾）
思路：当正确答案比错误答案还多时，不妨随便蒙一个。
```
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        while(True):
            L = random.randint(1,n)
            R = n-L
            if '0' not in str(L) and '0' not in str(R):
                return [L,R]
```

**时间复杂度：`O(n^0.046 * lg(n))`，两个部分：**

**· While循环：`O(n^0.046)`。**
  平均循环次数 == 命中无零整数的期望。生成数字每增加一位，就会有1/10的几率命中0，使得命中期望变为原来的10/9。
  因此，平均循环次数为 `(10/9) ^ lg(n)`，整理得`n ^ lg(10/9)`，约为n的0.046次幂。
  考虑到`2147483647 ^ 0.046 = 2.673`,在Int范围和O(1)几乎没啥区别。

**· If校验：`O(lg(n))`**
  `'0' not in String`需要lg(n)的时间复杂度。