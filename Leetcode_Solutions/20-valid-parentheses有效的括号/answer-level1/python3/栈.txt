### 解题思路
此处撰写解题思路
看了大神的思路确实清奇，这种就是采取栈的方式是最简单的。如果这里加一句，不只是特殊字符，还有别的任意字符，这个题的就有点深度了
### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        dic = {'{': '}',  '[': ']', '(': ')', '?': '?'}
        stack = ['?']
        for c in s:
            if c in dic.keys(): 
                stack.append(c)
            elif dic[stack.pop()] != c:
                 return False 
        return len(stack) == 1
```