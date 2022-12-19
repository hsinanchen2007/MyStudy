用list作为一个栈，每次遇见‘+-*/’就取出两个进行运算，将结果入栈，栈中最后只会剩下一个数字，就是我们要的答案。
代码如下，写得相当清晰简洁，故不需要注释了：
```
class Solution:
    def evalRPN(self, tokens):
        mid = []
        for i in tokens:
            if not mid:
                mid.append(int(i))
                continue
            if i =='+':
                x = mid[-1]
                y = mid[-2]
                s = y+x
                del mid[-1]
                del mid[-1]
                mid.append(s)
                continue
            if i =='-':
                x = mid[-1]
                y = mid[-2]
                s = y-x
                del mid[-1]
                del mid[-1]
                mid.append(s)
                continue
            if i =='*':
                x = mid[-1]
                y = mid[-2]
                s = y*x
                del mid[-1]
                del mid[-1]
                mid.append(s)
                continue
            if i =='/':
                x = mid[-1]
                y = mid[-2]
                s = int(y/x)
                del mid[-1]
                del mid[-1]
                mid.append(s)
                continue
            mid.append(int(i))
        return mid[0]

```