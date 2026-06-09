### 解题思路
第一种暴力求解
第二种巧妙利用list的replace方法：评论区参考的，记录一下

### 代码

```python
class Solution(object):
    # def isValid1(self, s):
    #     """
    #     :type s: str
    #     :rtype: bool
    #     """
    #     mylist=[]
    #     for i in s:
    #         if i == '(' or i=='{' or i=='[':
    #             mylist.append(i)
    #         else:
    #             if mylist==[]:
    #                 return False
    #             if i==')':
    #                 if mylist.pop()=='(':
    #                     continue
    #                 else:
    #                     return False
    #             if i==']':
    #                 if mylist.pop()=='[':
    #                     continue
    #                 else:
    #                     return False
    #             if i=='}':
    #                 if mylist.pop()=='{':
    #                     continue
    #                 else:
    #                     return False
    #     if mylist==[]:
    #         return True
    #     else:
    #         return False 
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        while '()'in s or '[]'in s or '{}'in s:
            s=s.replace('()','')
            s=s.replace('[]','')
            s=s.replace('{}','')
        return s==''
            
```