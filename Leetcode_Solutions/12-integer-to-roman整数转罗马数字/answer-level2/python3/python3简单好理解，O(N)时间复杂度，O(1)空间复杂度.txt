# 思路
没有参考其他任何的理解，没想到跟很多人想的差不多。

1). 将所有的字符数字映射为table中去， 包括特殊的900，400，90等；

2). 每次将num扣除table中的key数字，比如 1994 = 1000 + 900 + 90 + 4；
    **并注意table中的索引idx需要维持在刚好小于当前num的位置。**

# 代码
```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        table = [
            [1000, 'M'], 
            [900, 'CM'], 
            [500, 'D'], 
            [400, 'CD'], 
            [100, 'C'], 
            [90, 'XC'], 
            [50, 'L'], 
            [40, 'XL'], 
            [10, 'X'], 
            [9, 'IX'], 
            [5, 'V'], 
            [4, 'IV'], 
            [1, 'I']
        ]
        ans, idx = '', 0
        while num != 0:
            while num < table[idx][0]:
                idx += 1
            num -= table[idx][0]
            ans += table[idx][1]
        return ans
```