```
class Solution:
    def isValid(self, s: str) -> bool:
        left, right = list("{[("), list("}])")
        stack = []
        if s == "":
            return True
        for item in s:
            if item in left:
                stack.append(item)
            if item in right:
                if not stack:
                    return False
                target = stack[-1]
                if left.index(target) != right.index(item):
                    return False
                else:
                    stack.pop()
        return len(stack) == 0
```
想法：用列表代替栈。具体操作：
1.当我们碰到左括号的时候，放入栈中(stack.push())
2.碰到右括号的时候，找列表中的最后元素(stack.top())
如果栈为空：直接返回False（没有对应的了）
如果栈顶元素与该右括号不匹配：也返回False（形如"(]"的不匹配状况）
如果栈顶的左括号与该右括号匹配：去掉这个左括号(stack.pop())
3.最后检查栈是否为空，返回结果
