### 解题思路
用数组实现入栈出栈，复习了list的操作，感觉python在静态队列的实现上挺友好

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        sets={"(":1,")":-1,"{":9,"}":-9,"[":100,"]":-100," ":0}
        sum1=[]
        j=0
        for i in s:
            if sets.get(i)>=0:
                sum1.append(sets.get(i))
                j+=1
                continue
            else:
                if len(sum1)!=0:
                    if sum1[j-1]==-sets.get(i):
                        del sum1 [j-1]
                        j=j-1
                    else:
                        return False
                else:
                    return False
        return False if sum1 else True
```