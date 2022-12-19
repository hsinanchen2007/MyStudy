### 解题思路
1.对每一层依次遍历，用list level表示当前探索的层，在遍历中把当前层所有元素放入结果列表中，并时刻更新level
执行用时 :20 ms, 在所有 Python 提交中击败了86.84%的用户
内存消耗 :13.2 MB, 在所有 Python 提交中击败了5.97%的用户
时空复杂度都为n
2.递归
时间空间复杂度也为n
执行用时 :28 ms, 在所有 Python 提交中击败了42.07%的用户
内存消耗 :13.7 MB, 在所有 Python 提交中击败了5.97%的用户

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        ans, level = [], [root]
        while level:
            ans.append([node.val for node in level])
            temp = []
            for node in level:
                temp.extend([node.left, node.right])
            level = [leaf for leaf in temp if leaf]
        return ans 

    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        res = []
        
        def helper(root, depth):
            if not root: return 
            if len(res) == depth:
                res.append([])
            res[depth].append(root.val)
            helper(root.left, depth + 1)
            helper(root.right, depth + 1)
        helper(root, 0)
        return res
```