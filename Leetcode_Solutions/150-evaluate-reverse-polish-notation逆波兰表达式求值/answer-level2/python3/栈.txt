
**测试用例：**

* 功能测试：\["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"\]
* 边界测试：
* 负面测试：

## 方法：栈

遍历元素。
- 当元素是数字时入栈。
- 当元素为符号时，将栈顶的两个元素出栈，计算结果，将结果入栈。
- 注意：后出栈元素应该是元素运算的x，先出栈元素应该是元素运算的y。

```python
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        f = {"*": lambda x,y: x * y,
            r"/": lambda x,y: int(y/x),
            "+": lambda x,y: x + y,
            "-": lambda x,y: y - x}
        for token in tokens:
            if token in r"*/+-":
                a = stack.pop()
                b = stack.pop()
                stack.append(f[token](a,b))
            else:
                stack.append(int(token))
        return stack[0]
```

**复杂度分析：**

* 时间复杂度：O(n)
* 空间复杂度：O(n)