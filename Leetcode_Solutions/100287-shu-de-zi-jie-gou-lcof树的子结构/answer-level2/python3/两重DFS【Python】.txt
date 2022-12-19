### 思路

**两重DFS**

```
第一重：找到起点。先判断当前节点，如果不对就判断左子树和右子树。
第二重：从找到的起点开始判断剩下的点。
```

##### Python3代码

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        if not A or not B:
            return False
        return self.dfs(A, B) or self.isSubStructure(A.left, B) or self.isSubStructure(A.right, B)
            
        
    def dfs(self, A: TreeNode, B:TreeNode):
        if not B:
            return True
        if not A:
            return False
        if not A.val == B.val:
            return False
        # A树的根与B树的根相等
        return self.dfs(A.left, B.left) and self.dfs(A.right, B.right)  # 注意这里是 and
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/Interview-26-shu-de-zi-jie-gou-lcof/26.py)

### 相似题目

[LeetCode 1367. 二叉树中的列表](https://leetcode-cn.com/problems/linked-list-in-binary-tree/)