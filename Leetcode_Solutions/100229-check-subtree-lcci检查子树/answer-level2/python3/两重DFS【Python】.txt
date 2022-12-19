【更新】代码最后一行应该是 and，感谢 [@带带算法鸭](https://leetcode-cn.com/u/zhaohelei/) 指出。

### 思路

**两重DFS**

```
第一重：在 t1 中找到 t2 的起点。先判断 t1 当前节点，如果不对就判断 t1 左子树和 t1 右子树。
第二重：从找到的起点开始判断剩下的点，t1 和 t2 同步左右子树搜索。
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
    def checkSubTree(self, t1: TreeNode, t2: TreeNode) -> bool:
        if t1 == None:
            return False
        if t2 == None:
            return True
        # find the root of t2 in t1
        return self.dfs(t1, t2) or self.checkSubTree(t1.left , t2) or self.checkSubTree(t1.right, t2)
    
    def dfs(self, t1, t2):
        # t2 is over
        if t2 == None:
            return True
        # t2 is not over and t1 is over
        elif t2 != None and t1 == None:
            return False
        # not equal
        elif t2.val != t1.val:
            return False
        # equal, then search left and right
        else:
            return self.dfs(t1.left, t2.left) and self.dfs(t1.right, t2.right)  # 注意这里是and
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/Interview-04.10-check-subtree-lcci/0410.py)

### 相关题目

[LeetCode 1367. Linked List in Binary Tree二叉树中的列表](https://leetcode-cn.com/problems/linked-list-in-binary-tree/)