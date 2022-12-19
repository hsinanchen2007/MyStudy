
![Screen Shot 2020-02-05 at 12.19.26 PM.png](https://pic.leetcode-cn.com/727a673808b4a454b9c038dbc6b46812d5136c1e4d270b364d626949bdbcb1b2-Screen%20Shot%202020-02-05%20at%2012.19.26%20PM.png)


### 解题思路
从 1 到 n 中的前 k 个数开始迭代枚举, 每次迭代将 k 个数中的最后一个加 1 并记录结果, 当组合列表中的最后一个数超过有效范围时, 将其从组合列表中弹出放入栈中, 将现在组合列表里的最后一个数再次加 1. 将栈中的元素依次弹出, 将值设置为组合列表最后一个数字加 1, 再放入组合列表尾部. 照此规则枚举直到没有更大的数字组合.


### 代码

```python
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        combined = list(range(1, k + 1))
        res = []
        stack = []
        while combined[0] < n + 1 - k:
            res.append(combined.copy())
            combined[-1] += 1
            # 进位 step 1: 当组合列表中的最后一个数超过有效范围时, 将其从组合列表中弹出放入栈中, 将现在组合列表里的最后一个数再次加 1
            while combined[-1] == n + 1 - k + len(combined):
                stack.append(combined.pop())
                combined[-1] += 1
            # 进位 step 2: 将栈中的元素依次弹出, 将值设置为组合列表最后一个数字加 1, 再放入组合列表尾部
            while stack:
                stack.pop()
                combined.append(combined[-1] + 1)
        res.append(combined)
        return res
```