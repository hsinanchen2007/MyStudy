### 解题思路
#### **一般的括号匹配问题都可以用栈解决，括号长度问题可以用下标。**
基础思路————**遇到'('就添加到`stack`中，遇到')'就`pop()`**

### 代码

```python3
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        if not s:
            return 0
        # 用栈记录括号的位置，添加一个-1，防止出现一开始就')'
        stack = [-1]
        ss = list(s)
        max_len = 0
        for i, item in enumerate(ss):
            # 遇到'('就将其位置添加到stack中
            if item == '(':
                stack.append(i)
            # 遇到')'就将stack最顶端元素pop，代表删去一对有效括号
            elif item == ')':
                stack.pop()
                # 如果stack中没有元素了 说明前面已经匹配好了 又进来一个')'，
                # 那么加到stack中，更新位置，计算后面的有效括号长度
                if len(stack) == 0:
                    stack.append(i)
                # 如果还有元素，说明又多了一对匹配括号，更新max_len
                else:
                    max_len = max(max_len, i-stack[-1])
        return max_len



```