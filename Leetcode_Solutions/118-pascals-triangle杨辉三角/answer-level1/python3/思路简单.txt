先把0和1的特殊情况排除，然后就是前面一行每两个数字相加得到下一行，最后给生成的新的一行前后端都加个1。
思路应该算是比较容易想到的一种。

```
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0:
            return []
        if numRows == 1:
            return [[1]]
        result=[[1],[1,1]]
        for i in range(numRows)[2:]:
            temp=[]
            #这里result_add取得就是最新生成的完整一行，我们当前行要根据这个来计算
            result_add=result[-1]
            for j in range(len(result_add)-1):
                temp.append(result_add[j]+result_add[j+1])
            #给首尾加个1
            temp.insert(0,1)
            temp.append(1)
            result.append(temp)
        return result
```

欢迎讨论