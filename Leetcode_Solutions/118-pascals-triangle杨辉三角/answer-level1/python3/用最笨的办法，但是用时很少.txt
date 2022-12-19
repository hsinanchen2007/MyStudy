### 解题思路
一个初学者，只能最简单的循环解决

### 代码

```python3
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if not numRows:return []
        if numRows == 1:return [[1]]
        if numRows == 2:return [[1],[1,1]]
        len_ = 3
        a = []
        b = [1,1]
        res = [[1],[1,1]]
        while len_ <= numRows:
            for i in range(len_):
                if i == 0 or i == len_ - 1:
                    a.append(1)
                else:
                    a.append(b[i-1] + b[i]) 
            res.append(a)
            b = a.copy()
            a = []
            len_ += 1
        return res
```