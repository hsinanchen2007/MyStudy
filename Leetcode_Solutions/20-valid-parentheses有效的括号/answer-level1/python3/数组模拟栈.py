### 解题思路
括号问题是经典的栈结构可实现的问题，在python中用列表list来模拟栈结构。

- 1.字符串的长度必须是偶数，且长度要大于2
- 2.遍历字符串s,只要是左括号就入栈，右括号就和栈顶元素的位置进行比较
- 3.遍历结束后，栈一定要为空，即数组的长度为0时才满足条件。

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 != 0 and len(s)<2:
            return False
        
        left = '([{'
        right = ')]}'

        res = []

        for c in s:
            if c in left:
                res.append(c)
            elif c in right:
                if len(res)== 0:
                    return False
                if right.index(c) != left.index(res.pop()):
                    return False
        if len(res)>0:
            return False
        return True

```