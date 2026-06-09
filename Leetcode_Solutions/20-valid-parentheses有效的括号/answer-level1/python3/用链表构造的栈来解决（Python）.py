```
class Node:
    """结点"""
    
    def __init__(self, elem, next_):
        self.elem = elem
        self.next = next_


class Stack:
    """栈"""

    def __init__(self):
        self._top = None

    def is_empty(self):
        return self._top is None

    def top(self):
        if self.is_empty():
            raise ValueError
        return self._top.elem

    def push(self, elem):
        self._top = Node(elem, self._top)

    def pop(self):
        if self.is_empty():
            raise ValueError
        p = self._top
        self._top = p.next
        return p.elem

class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = Stack()
        map_parentheses = {')': '(', ']': '[', '}': '{'}

        for char in s:
            if char in map_parentheses:
                try:
                    top_elem = stack.pop() 
                except ValueError:
                    top_elem =  '#'
                if top_elem != map_parentheses[char]:
                    return False
            else:
                stack.push(char)
        return stack.is_empty()
```
比用list慢点