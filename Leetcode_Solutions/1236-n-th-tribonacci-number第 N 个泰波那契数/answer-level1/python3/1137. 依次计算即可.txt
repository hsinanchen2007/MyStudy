### 解题思路
其实就是一次一次计算，因为0-2已经给定值了，因此再循环n-2次，即可求出指定n的对应的泰波那契数。

### 代码

```python3
class Solution:
    def tribonacci(self, n: int) -> int:

        tybo = [0, 1, 1]

        for i in range(n-2):
            next_tybo = sum(tybo[i:i+3])
            tybo.append(next_tybo)
        
        return tybo[n]


```