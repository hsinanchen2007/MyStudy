### 解题思路
此处撰写解题思路
最终行 = [0,前一行] + [前一行，0]
最终行元素数 = rowindex + 1
知道以后就很简单啦
### 代码

```python3
class Solution:
    def getRow(self, rowIndex: int):
        if rowIndex == 0:
            return [1]
        ans = [1,1]
        a= []
        b = []
        while True:
            if len(ans) == rowIndex + 1:
                break
            a = ans[:]
            a.append(0)
            b = ans[:]
            b.insert(0,0)
            ans = [i+j for i,j in zip(a,b)]#两个列表元素两两对应相加后组成的列表


        return ans
```