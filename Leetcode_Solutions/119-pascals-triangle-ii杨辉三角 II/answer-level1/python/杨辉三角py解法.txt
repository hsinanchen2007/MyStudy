### 解题思路
1.判断索引，如果为0，返回[1]
2.判断res长度跟索引大小，遍历获取值并存入res中
3.最后输入res[index]
### 代码

```python
class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if rowIndex == 0:
            return [1]
        res=[[1]]
        while len(res) <= rowIndex:
            newRows = [a+b for a,b in zip([0]+res[-1],res[-1]+[0])]
            res.append(newRows)
        return res[rowIndex]
```