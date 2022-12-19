### 解题思路
思路：split分离整句，对每个i都[::-1]反向，最后join输出字符串形式

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        res=[]
        s_lis=s.split()
        for i in s_lis:
            i=i[::-1]
            res.append(i)
        return " ".join(res)
```