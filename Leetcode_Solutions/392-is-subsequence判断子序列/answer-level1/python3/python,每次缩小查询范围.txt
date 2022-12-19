### 解题思路
遍历s，对于每一个字符，找到最靠前的索引，缩小查询范围，逐个查询，如果没有出现在后续子字符串中，返回False，否则返回True

### 代码

```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        for char in s:
            if char in t:
                index=t.index(char)
                t=t[index+1:]
            else:
                return False
        return True





        
       
```