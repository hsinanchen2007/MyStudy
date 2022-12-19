### 解题思路
模拟即可
![图片.png](https://pic.leetcode-cn.com/79752eb8f3afe2ea750d5fe6cdd3949ec7242c1dd10aac9ba0dc977eced5ab72-%E5%9B%BE%E7%89%87.png)
### 代码

```python3
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack = []
        while pushed:
            stack.append(pushed.pop(0))
            while stack and popped and stack[-1] == popped[0]:
                popped.pop(0)
                stack.pop()
        return False if stack else True
```