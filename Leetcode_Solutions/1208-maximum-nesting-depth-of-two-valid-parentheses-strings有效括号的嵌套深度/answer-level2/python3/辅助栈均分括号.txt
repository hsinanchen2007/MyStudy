### 解题思路
题目介绍的主要是有效括号和括号深度的定义

然后需要max（A，B）尽可能地小，而seq的深度是一定的，那么需要把括号均匀分配给A和B
右括号和左括号总是配对的，所以只需要考虑左括号即可

难理解也难转化的来了，其实要实现上面的要求只需要把左括号按深度的奇偶分给A和B就可以了

具体实现的时候可以每次碰见左括号就把深度加1，然后进行分配
遇到右括号的时候先按照和最近的左括号一样的奇偶性进行分配，然后把深度减1

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        ans = []
        d = 0
        for c in seq:
            if c == "(":
                d += 1
                ans.append(d%2)
            if c == ")":
                ans.append(d%2)
                d -= 1
        
        return ans 
```