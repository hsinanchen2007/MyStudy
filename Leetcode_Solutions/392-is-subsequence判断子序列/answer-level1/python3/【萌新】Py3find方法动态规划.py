### 解题思路
遍历s，对于每个i，如果在t中就返回索引loc
用find函数的beg关键字，对字符串进行“切片”

### 代码

```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        loc=-1
        for i in s:
            if i in t: 
                loc=t.find(i,loc+1)
                if loc==-1:
                    return False
            elif i not in t:
                return False
        return True
```