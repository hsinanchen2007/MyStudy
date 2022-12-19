### 解题思路
堆栈解决二叉树层平均值

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        if root is None:
            return []
        stack, ret = [[root]], []
        temp = stack.pop()
        while len(temp) > 0:
            tempStack = []
            sum_ = 0
            for i in temp:
                sum_ += i.val
                if i.left:
                    tempStack.append(i.left)
                if i.right:
                    tempStack.append(i.right)
            stack.append(tempStack)
            ret.append((sum_) / len(temp))
            temp = stack.pop()
        return ret
```