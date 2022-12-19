### 解题思路
![屏幕快照 2019-12-18 11.05.37.png](https://pic.leetcode-cn.com/c18cd720bf28e3a1b868666ccf413ea4328c5c88684c8a0a9bac6e480b7592a7-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-12-18%2011.05.37.png)

如图。
先转换成set排除重复元素。
对于回文串，偶数的元素直接保留放两边；若有奇数的要去掉一个，变成偶数放两边，但仍允许有一个奇数放中间。
如：aaaaabbbc a b c 个数分别是5 3 1 一共有三个元素是奇数，要选其中两个变成偶数
aabbbc  a b c 个数分别是2 3 1 一共有两个元素是奇数，要选其中一个变成偶数
若都是偶数，如aabbbb 则原序列长度输出
     

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        a = set(s)
        b = list(a)
        oddc = 0
        flag = 0
        for i in range(len(b)):
            c = s.count(b[i])
            if c % 2 != 0:
                oddc += 1
                flag = 1
        l = len(s) - (oddc - flag)
        return l
```