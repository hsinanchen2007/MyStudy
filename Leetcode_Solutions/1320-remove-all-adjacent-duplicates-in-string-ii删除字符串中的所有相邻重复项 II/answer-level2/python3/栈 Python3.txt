**思路：**

将元素依次入栈并统计元素数量。每次入栈判断是否和栈顶元素相同：如果与栈顶元素相同，那么将栈顶元素的数量加 1；如果栈顶元素数量达到 3，则将栈顶元素出栈；如果待入栈元素与栈顶元素不同，那么直接入栈并将该元素个数置为 1。遍历完字符串之后，将栈中剩余元素拼接即为答案。

**图解：**

![图解](https://pic.leetcode-cn.com/c496b95ca5faee769286cffbf58043866db9265dad0fb5d2f04c4131456f42de.gif)

**代码：**

```python
class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        n = len(s)
        stack = []
        for c in s:
            if not stack or stack[-1][0] != c:
                stack.append([c, 1])
            elif stack[-1][1] + 1 < k:
                stack[-1][1] += 1
            else:
                stack.pop()
        ans = ""
        for c, l in stack:
            ans += c * l
        return ans
```

