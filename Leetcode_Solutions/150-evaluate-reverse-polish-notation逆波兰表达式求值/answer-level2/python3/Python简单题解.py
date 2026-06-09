### 解题思路
此处撰写解题思路
这一题的基本解法就是用栈；不过用python的时候需要注意两点：
1. 可以用eval()函数来计算字符串表达式
2. python的整除(//)是向下取整，在负数域的时候会比正确答案-1，所以用int(a/b)来表示整除（int是向0取整）
### 代码

```python3
class Stack:
    lst = []
    def push(self, val):
        self.lst.append(val)

    def pop(self):
        return self.lst.pop()

    def isEmpty(self):
        if len(self.lst) == 0:
            return True
    
    def top(self):
        return int(self.lst[-1])

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operator = ['+', '-', '*', '/']
        s = Stack()
        for item in tokens:
            if item in operator:
                b = s.pop()
                a = s.pop()
                res = eval("{0}{1}{2}".format(a, item, b))
                s.push(int(res))
            else:
                s.push(item)
        return s.top()
```