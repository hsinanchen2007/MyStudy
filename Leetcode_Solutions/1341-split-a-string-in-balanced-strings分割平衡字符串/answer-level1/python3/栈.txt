### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def balancedStringSplit(self, s: str) -> int:
        ans=0
        stack=[]
        dic={'L':'R','R':'L'}
        for i in s:
            if stack==[]:
                ans+=1
            if dic[i] in stack:
                stack.pop()
            else:
                stack.append(i) 
        return ans

```