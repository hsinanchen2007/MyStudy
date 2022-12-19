    刚开始你可能会被NestedInteger搞懵，这是要实现NestedInteger嘛？
    仔细阅读它的注释就会发现，这是一个创建嵌套列表的接口，你不需要去实现或者推测它是如何实现的.
    换句话说，这是一个辅助类，我们在实现的时候只需要转换成它规定的方式即可.

我们维护一个栈stack用于存储嵌套列表，接下来我们对可能出现的情况分别进行处理：

### Step1： 第一个字符不是'['，说明遇到了数字，那么我们就直接返回
    注意要包装成NestedInteger对象：
```        
    if s[0] != '[':
        return NestedInteger(int(s))
```
### Step2： 第一个字符是'['，每一个字符可能的情况共有5种，我们分别讨论
>---
##### - 数字：计算10进制数字大小即可

##### - 负号：设置符号位为-1

##### - 左括号：栈append一个空的NestedInteger对象

##### - 逗号：前面是数字，把栈顶的元素pop出来，然后append(前面的数字)，重新压入栈中
        其实，题目说明了这些字符串都是格式良好的，遇到逗号说明前面肯定有'['，此时栈一定是有元素的

##### - 右括号：处理同逗号；但还需对嵌套列表进行处理：
        把栈顶元素pop出来(即嵌套底层的list)，
        把新的栈顶(即嵌套的高层list)append刚才pop出来的底层的list，重新压入栈中

>---


实现如下：


``` 
class Solution:
    def deserialize(self, s: str) -> NestedInteger:
        
        if s[0] != '[':
            return NestedInteger(int(s))
        
        stack = []
        # num为数字，sign为符号为，is_num为前一个是否为数字
        num, sign, is_num = 0, 1, False
        
        for c in s:
            if c.isdigit():
                num = num * 10 + int(c)
                is_num = True
            elif c == '-':
                sign = -1
            elif c == '[':
                stack.append(NestedInteger())
            elif c == ',' or c == ']':
                # 把刚才遇到的数字append进去
                if is_num:
                    cur_list = stack.pop()
                    cur_list.add(NestedInteger(sign * num))
                    stack.append(cur_list)
                num, sign, is_num = 0, 1, False

                # 此时为嵌套列表
                if c == ']' and len(stack) > 1:
                    cur_list = stack.pop()
                    stack[-1].add(cur_list)

        return stack[0]

```
