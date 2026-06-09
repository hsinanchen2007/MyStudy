我们可以直接利用对列表[-1]的处理来代替使用stack
一下是我的代码：

```
class Solution(object):
    def isValid(self, s):
        a = [1,]
        m = len(s)%2
        if m != 0:
            return False
        for i in s:
            if a[-1] == "(" and i == ")":
                a = a[:-1]  #This place cannot use remove, because this is stack. You can only remove the last one but not the same value one
            elif a[-1] == "[" and i == "]":
                a = a[:-1]
            elif a[-1] == "{" and i == "}":
                a = a[:-1]
            else:
                a.append(i)
        return len(a)==1
        """
        :type s: str
        :rtype: bool
        """
```
