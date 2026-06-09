### 解题思路
![image.png](https://pic.leetcode-cn.com/34550d558cb8e986cfe93ed29862d08f6353db2e248164d43c61c43a502a44a5-image.png)

使用left存储左括号到右括号的对应关系, 使用right存储右括号到左括号的对应关系
stack作为堆栈使用只在尾部插入数据和弹出数据
需要注意的是 判断stack是否为空

注: 我在解题的时候以为还会出现非括号的情况, 因此还有else:continue的判断

### 代码

```python3
class Solution:
    left = {'(':')', '[': ']', '{': '}'}
    right = {')':'(', ']':'[', '}':'{'}
    
    def isValid(self, s: str) -> bool:
        stack = []
        for c in s:
            if c in self.left:
                stack.append(c)
            elif c in self.right:
                if len(stack) < 1 or stack.pop() != self.right[c]:
                    return False
            else:
                continue
        return not stack
```