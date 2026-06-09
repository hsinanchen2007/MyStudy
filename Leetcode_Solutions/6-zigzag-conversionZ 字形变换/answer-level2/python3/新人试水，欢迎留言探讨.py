### 解题思路
建立一个2维空数组，然后设置一个加法因子，发现每次加到numRows最大就改变符号进行加法，将数字依次填入数组中，注意初始add = -1，因为初始为0，当时就变化加法因子符号。

### 代码

```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        res_array = [[] for _ in range(numRows)]
        num = 0
        add = -1
        for i in s:
            if num == 0 or num == numRows - 1:
                add = -add
            res_array[num].append(i)
            num += add
                
        return ''.join([''.join(i) for i in res_array])
```