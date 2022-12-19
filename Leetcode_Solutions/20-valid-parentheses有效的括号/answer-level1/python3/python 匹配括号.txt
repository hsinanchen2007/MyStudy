### 解题思路
将左括号压入list中，遇见右括号进行pop比较。
注：不要遗忘左括号多的情况：最后判断list是否为空
   不要遗忘右括号多的情况：pop前判断list是否为空
### 代码

```python
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        mylist=[]
        for i in s:
            if i == '(' or i=='{' or i=='[':
                mylist.append(i)
            else:
                if mylist==[]:
                    return False
                if i==')':
                    if mylist.pop()=='(':
                        continue
                    else:
                        return False
                if i==']':
                    if mylist.pop()=='[':
                        continue
                    else:
                        return False
                if i=='}':
                    if mylist.pop()=='{':
                        continue
                    else:
                        return False
        if mylist==[]:
            return True
        else:
            return False 
```