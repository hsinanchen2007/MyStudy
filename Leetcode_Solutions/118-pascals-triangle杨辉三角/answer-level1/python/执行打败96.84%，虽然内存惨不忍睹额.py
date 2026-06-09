### 解题思路
跟官方差不多的意思，但官方的好简练啊啊啊，妙啊

### 代码

```python
class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows == 0:
            return []
        else:
            ress = [[1]]
            if numRows == 1:
                return ress
            else:
                for numRow in range(1,numRows):
                    res = []
                    a = 0
                    for i in range(numRow-1):
                        a = ress[numRow-1][i] + ress[numRow-1][i+1]
                        res.append(a)
                    res.insert(0,1)
                    res.append(1)
                    ress.append(res)
                return ress
```