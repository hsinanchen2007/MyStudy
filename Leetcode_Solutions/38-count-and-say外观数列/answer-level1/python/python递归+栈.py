在递归思想基础上：建立一个栈，相同元素入栈，当i+1的元素与栈中不同时，清空栈并压入新的元素
代码如下：
```
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n==1: return '1'
        pre = self.countAndSay(n - 1)
        stack = []
        final = ''
        for i in range(len(pre)):
            if pre[i] in stack or not stack:
                stack.append(pre[i])
            else:
                final += str(len(stack)) + str(stack[0])
                stack = []
                stack.append(pre[i])
        final += str(len(stack)) + str(stack[0])
        return final
```
