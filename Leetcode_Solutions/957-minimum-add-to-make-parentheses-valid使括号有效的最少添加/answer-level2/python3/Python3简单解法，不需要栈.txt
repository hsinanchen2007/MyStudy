状态变量ans，字符为左括号加1，为右括号减1
当ans小于0时，右括号比左括号多，则要添加左括号，计数count加一，ans加1（表示该步骤添加了一个左括号）
最后ans大于0，则表示左括号比右括号多，则要添加对应数目的右括号，使括号有效

```
class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        ans = 0 
        count = 0
        for i in S:
            if i == '(':
                ans += 1
            else:
                ans -= 1
            if ans < 0:
                count += 1
                ans += 1
        count += ans
        return count
```
