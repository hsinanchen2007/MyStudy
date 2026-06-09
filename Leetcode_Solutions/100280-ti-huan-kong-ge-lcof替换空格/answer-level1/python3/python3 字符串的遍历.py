### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def replaceSpace(self, s: str) -> str:
        res=''
        for i in s:
            if i==' ':
                res+='%20'
            else:
                res+=i
            #i+=1
        return res
```