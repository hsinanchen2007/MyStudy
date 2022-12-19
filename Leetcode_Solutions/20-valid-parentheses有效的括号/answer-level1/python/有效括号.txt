### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s)==0 :return True
        if len(s)%2 ==1:return False
        l_left = ['(','[','{']
        com = ["()","[]","{}"]
        stack=[]
        for str in s:
            if str in l_left:
                stack.append(str)
            else:
                if len(stack)== 0: return False
                p = stack[len(stack)-1]+str
                if p in com :
                    stack.pop()
                else:
                    return False

        return True if len(stack)==0 else False
       
```