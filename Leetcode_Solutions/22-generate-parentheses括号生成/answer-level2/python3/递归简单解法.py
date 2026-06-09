使用递归，递归结束条件n==1时，返回["()"]
遍历上一次的结果列表，再遍历每个字符串元素，在字符串的每个索引位置插入"()",组成新的字符串，判断新的字符串
是否在本次的结果中，若没有，则添加到本次结果列表中

```python []
class Solution:
    def generateParenthesis(self, n):
        if n==1:
            return ["()"]
        lastRes=self.generateParenthesis(n-1)
        res=[]
        for i in lastRes:
            for j in range(len(i)):
                newStr=i[:j]+"()"+i[j:]
                if newStr not in res:
                    res.append(newStr)
        return res
```

