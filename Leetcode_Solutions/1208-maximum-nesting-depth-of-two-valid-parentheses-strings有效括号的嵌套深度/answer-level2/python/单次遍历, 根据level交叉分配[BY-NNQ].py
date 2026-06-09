### 解题思路
> 根据深度， 同一深度分给一个组， 不同深度交叉分配即可； 不用队列，简单变量记录当前深度即可；

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        if not seq:
            return []
        ans = [0] * len(seq)
        level = 0
        for i, c in enumerate(seq):
            if c == '(':
                ans[i] = level % 2
                level += 1
            elif c == ')':
                level -= 1
                ans[i] = level % 2

        return ans
```

###
```
执行用时 :64 ms, 在所有 Python3 提交中击败了32.08%的用户
内存消耗 :14.1 MB, 在所有 Python3 提交中击败了16.67%的用户
```