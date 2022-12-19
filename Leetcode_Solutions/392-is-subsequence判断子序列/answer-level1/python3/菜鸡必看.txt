### 解题思路
这也是dp
不过讲真不需要哪怕一个一维的状态表
直接一个标志位就ok了
所以给的easy难度没毛病
### 代码

```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if not s:
            return True
        max=0
        for i in t :
           if i==s[max]:
               max+=1
               if max==len(s) :
                   return True
        return False
```