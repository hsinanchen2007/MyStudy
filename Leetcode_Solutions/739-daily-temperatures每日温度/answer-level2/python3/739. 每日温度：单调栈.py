
```python []
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        stack = []
        for i, t in enumerate(T):
            while stack and t > T[stack[-1]]:
                j = stack.pop()
                T[j] = i - j
            stack.append(i)
        for i in stack:
            T[i] = 0
        return T
```

![image.png](https://pic.leetcode-cn.com/4e80ec090850b105d06459c2ef4385765f730804eb6ee2442b00b1e7a61d3520-image.png)
