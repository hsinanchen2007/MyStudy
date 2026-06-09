### 解题思路
主要就是在哈希表中放一个list

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        # 保存每层的叶子节点
        dt=collections.defaultdict(list)
        def helper(root,x) :
            if not root :
                return 
            if not root.left and not root.right :
                dt[x].append(root.val)
            helper(root.left,x+1)
            helper(root.right,x+1)
        helper(root,0)
        max=0
        for i in dt :
            if i >max :
                max=i
        return sum(dt[max])
```