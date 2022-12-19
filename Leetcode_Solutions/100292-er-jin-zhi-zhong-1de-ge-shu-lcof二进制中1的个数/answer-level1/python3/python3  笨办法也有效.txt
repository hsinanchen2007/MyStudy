### 解题思路
1. 首先把输入的十进制通过 bin() 转换成二进制的形式； 
2. 通过一个for 循环来统计 ‘1’的数量。


### 代码

```python3
class Solution:
    def hammingWeight(self, n: int) -> int:
        c = 0
        for i in (bin(n)):
            if i == '1':
                c+=1
        return c

```