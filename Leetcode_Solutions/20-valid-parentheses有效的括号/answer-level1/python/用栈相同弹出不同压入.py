### 解题思路


### 代码

```python
class Solution(object):
    def isValid(self, s):
        if not s:
            return True
        elif len(s)%2!=0:
            return False
        else:
            count = {'(': 1, ')': -1, '[': 2, ']': -2, '{': 3, '}': -3}
            stack,cur=[s[0]],''
            for i in range(1,len(s)):
                cur=s[i]
                if stack and count[stack[-1]]==-count[cur]:
                    stack.pop()
                else:
                    stack.append(s[i])
            if not stack:
                return True
            else:
                return False

```