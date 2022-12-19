### 解题思路
**1.迭代方法**
深度优先搜索 自顶向下遍历，将根节点的值分别加到子节点上，不断更新cur_sum值，只要碰到叶子节点，即比较cur_sum 与目标值的大小。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def hasPathSum(self, root, sum):
        if not root:return False
        cur_sum = 0
        stack = [root]
        while stack:
            root1 = stack.pop()
            if not root1:continue
            #根节点的值是不断变化的，根节点储存的值一直都是经由节点的和
            cur_sum = root1.val
            children = [root1.right,root1.left]
            #遇到子节点就比较大小
            if not any(children):
                if cur_sum == sum:return True
                else:continue
            #不是子节点，则需要更新经由节点和
            for c in children:
                if c:
                    c.val = c.val + root1.val
                    stack.append(c) 
        return False

```
### 解题思路
**2.递归思想**
```python
class Solution(object):
    def hasPathSum(self, root, sum):
        if not root:return False
        cur_sum = root.val
        children = [root.right,root.left]
        if not any(children):
            if cur_sum == sum:return True
            else:return False
        if root.right:
            root.right.val += root.val
        if root.left:
            root.left.val += root.val
        return self.hasPathSum(root.right,sum) or self.hasPathSum(root.left,sum)    


```