### 解题思路
之前有道题是判断字符串中括号的有效性，这道题算是那道题的一个拓展，所以直接想到用栈做。
之前的题的解法是，我们遍历字符串中的每个字符，先判断栈是否为空，如果为空则压栈，如果非空则将当前字符和栈顶字符进行比较进而判断是压栈还是弹栈，最后再判断栈是否为空进而获得答案。
本题思路和那道题思路非常相似，首先遍历所有字符，如果栈顶和当前字符匹配则弹栈，否则将当前字符压栈(当前字符下标, 字符)。当遍历完所有字符时，如果栈为空则说明字符串的括号都能匹配，直接返回字符串长度即可，如果非空，那么**栈中留存的字符是无法进行匹配的**，换句话说无法匹配的字符中间的字符串就是可匹配的，举个例子s = '()((())()'，遍历一遍后，栈中只剩一个元素(2, '(')分别对应无法匹配的括号的下标和该字符，那么由于只有一个不可匹配字符可以将字符串分成两个部分就是可匹配的长度，拓展一下，如果栈中有n个不可匹配字符，那就说明有n + 1段可匹配字符串（包括''），我们只需要求得n + 1段字符串的最大长度即可。

时间复杂度分析：遍历一次字符串O(n)，遍历一次不可匹配字符O(n)，总时间复杂度O(n) + O(n) = O(2n) = O(n)

ps: 我最开始也考虑过用dp做，奈何水平有限，没有想到dp怎么做。

### 代码

```python
class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = Stack()
        for ind, ch in enumerate(s):
            if stack.is_empty() or ch == stack.top()[1] or ch == '(': # 可以压栈
                stack.push((ind, ch))
            else:
                stack.pop()
        if stack.is_empty():
            return len(s)
        else:
            ind = len(s)
            max_len = 0
            while not stack.is_empty():
                temp_len = ind - stack.top()[0] - 1
                if temp_len > max_len:
                    max_len = temp_len
                ind = stack.top()[0]
                stack.pop()
            if ind > max_len: # 即[0:ind]长度
                max_len = ind
        return max_len

class Stack(object):
    def __init__(self):
        self.stack = []

    def push(self, val):
        self.stack.append(val)

    def pop(self):
        if self.is_empty():
            raise Exception('stack is empty!')
        del self.stack[-1]

    def is_empty(self):
        return True if len(self.stack) == 0 else False

    def top(self):
        if self.is_empty():
            raise Exception('stack is empty!')
        return self.stack[-1] 
```