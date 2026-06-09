直接在result这个当中更改
result[j]=result[j]+result[j+1] 这一行直接更改，但是最后那个1更改不了，但是正好新的list最后也需要个1，但是开头那个1被更改了，所以需要在开头重新插入一个1，result.insert(0,1)
空间占用就是这个rusult，复杂度是O(k)
```
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex==0:
            return [1]
        result=[1,1]
        for i in range(rowIndex)[1:]:
            for j in range(len(result)-1):
                result[j]=result[j]+result[j+1]
            result.insert(0,1)
        return result
```
欢迎讨论