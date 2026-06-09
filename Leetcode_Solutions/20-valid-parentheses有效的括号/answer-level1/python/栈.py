用栈即可。

整道题目的代码如下：

```python
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """

        class Stack:
            def __init__(self): self.items = []
            def is_empty(self): return self.items == []
            def push(self, item): self.items.append(item)
            def pop(self): return self.items.pop()
            def peek(self): return self.items[len(self.items)-1]
            def size(self): return len(self.items)

        st = Stack()
        for i in range(len(s)):
            if s[i] == '(' or s[i] == '[' or s[i] == '{':
                st.push(s[i])
            elif s[i] == ')':
                if st.is_empty() or st.pop() != '(':
                    return False
            elif s[i] == ']':
                if st.is_empty() or st.pop() != '[':
                    return False
            elif s[i] == '}':
                if st.is_empty() or st.pop() != '{':
                    return False

        return st.is_empty()
```

