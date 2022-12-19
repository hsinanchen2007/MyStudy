### 解题思路
此处撰写解题思路
1. 使用后序dfs遍历，每次拿到节点的深度，如果答案数组中的长度小于该深度，直接append[root.val]，否则在该index的数组中append这个节点的值。

2. 使用前序dfs遍历，每次删除叶子节点，让叶子节点的父亲节点指向None。

### 代码

```python
1. 后序遍历，不删除节点
class Solution(object):
    def findLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        self.ans = []
        self.dfs(root)
        return self.ans
    
    def dfs(self, root):
        if not root:    return 0
        l = self.dfs(root.left)
        r = self.dfs(root.right)
        level = max(l, r) + 1
        if level > len(self.ans):
            self.ans.append([root.val])
        else:
            self.ans[level-1].append(root.val)
        return level

2. 前序遍历，删除节点
    def findLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        ans = []
        if not root:    return root
        dummy = TreeNode(0)
        dummy.left = root
        while dummy.left:
            self.tmp = []
            self.dfs(dummy.left, dummy, 1, 0)
            ans.append(self.tmp)
        return ans

    def dfs(self, root, parent, left, right):
        if not root.left and not root.right:
            self.tmp.append(root.val)
            if left:
                parent.left = None
            if right:
                parent.right = None
            return
        if root.left:
            self.dfs(root.left, root, 1, 0)
        if root.right:
            self.dfs(root.right, root, 0, 1)
            
```