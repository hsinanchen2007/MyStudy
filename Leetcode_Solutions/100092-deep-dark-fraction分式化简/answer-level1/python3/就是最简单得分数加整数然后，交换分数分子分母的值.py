### 解题思路
从后往前扫描，分数上下值交换，在加上前一个值，整数l加上分数n/m = (l * m+n)/m 。一直加到第一个值。

### 代码

```python3
class Solution:
    def fraction(self, cont: List[int]) -> List[int]:
        length = len(cont)
        res = [cont[length -1],1]
        for i in range(length - 2, -1, -1):
            temp = res[1]
            res[1] = res[0]
            res[0] = cont[i] * res[1] + temp
        return res

```