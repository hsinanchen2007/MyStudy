### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if not S:
            return ''
        a = list(S)

        res =[]
        res.append(a[0])
        tmp = 1
        for i in range(1,len(a)):
            if a[i] == a[i-1]:
               tmp+=1
            else:
                res.append(tmp)
                tmp = 1
                res.append(a[i]) 
        res.append(tmp)
        if len(res)>=len(a):
            return S
        else:
            return ''.join(str(i) for i in res)
```