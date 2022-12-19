### 解题思路
遍历第一个字符串每个字母  在第二个字符串里面查找 找到就删除
### 代码

```python3
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        for i in s1:
            if s2.find(i)+1:
                s2 = s2[:s2.index(i)] + s2[s2.index(i)+1:]
            else:
                return  False
            
        if len(s2) == 0:
            return True
```