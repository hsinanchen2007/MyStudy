### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dic = {}
        for i in s:
            dic[i]=dic.get(i,0)+1
        for i in t:
            if i in dic:
                dic[i]=dic.get(i,0)-1
            else:
                return False
        for i in s:
            if ((i in dic) and (dic[i]!=0)):
                return False
        return True
```