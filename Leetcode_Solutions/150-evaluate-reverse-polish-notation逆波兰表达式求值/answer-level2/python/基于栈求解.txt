用栈实现。遍历数组 `tokens`，如果遇到非运算符，则入栈，如果遇到运算符则弹出栈顶两个元素进行计算，然后将计算结果入栈。

例如 `["4", "13", "5", "/", "+"]` 计算过程如下：

![举个栗子](https://pic.leetcode-cn.com/7c8b7bb033261c4446a4ad6ed74ca42871e91fda46b497c97af4fd6b974f8d8e-%E6%9C%AA%E5%91%BD%E5%90%8D%E6%96%87%E4%BB%B6.png)

```python
class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = list()
        operations = {'+', '-', '*', '/'}
        
        for token in tokens:
            if token in operations:
                # 是操作符
                right = stack.pop()
                left = stack.pop()
                if token == '+':
                    tmp = left + right
                elif token == '-':
                    tmp = left - right
                elif token == '*':
                    tmp = left * right
                else:
                    if left * right >= 0:
                        tmp = left // right
                    else:
                        tmp = -(-left // right)
                    
                stack.append(tmp)
            else:
                # 不是操作符
                stack.append(int(token))
        
        return stack[0]
```