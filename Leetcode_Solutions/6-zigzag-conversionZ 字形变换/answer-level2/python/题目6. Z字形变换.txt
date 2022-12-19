### 解题思路
有一些思路，太复杂，看了大神的答案，豁然开朗，在此记录。

索引反向这样一种思路，可以为今后一些问题提供思路，是一种很灵活的方法。

将flag设置为1、-1，以满足不同位置处的索引构造。
### 代码

```python3
class Solution:
   
    def convert(self, s: str, numRows: int) -> str:
        if numRows < 2: return s
        res = ["" for _ in range(numRows)]
        i, flag = 0, -1
        for c in s:
            res[i] += c
            if i == 0 or i == numRows - 1: flag = -flag
            i += flag
        return "".join(res)
```