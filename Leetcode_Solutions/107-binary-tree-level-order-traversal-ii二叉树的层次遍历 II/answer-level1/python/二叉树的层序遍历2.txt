### 解题思路
和二叉树的层序遍历解题思路一样，只是在插入ans时每次插入第一个位置
迭代
递归(两种方法)
注意为什么第二种递归方法在插入元素时不是0，而是-(depth+1)，因为你要始终确保此时待插入的元素是插入对应的list中，由于递归，在此时插入元素时，前面可能已经有下面层的元素对应的list被插入了
### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        ans, level = [], [root]
        while level:
            ans.insert(0,[node.val for node in level])
            temp = []
            for node in level:
                temp.extend([node.left, node.right])
            level = [leaf for leaf in temp if leaf]
        return ans

    def levelOrderBottom(self, root):
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
        return res[::-1]

    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        res = []
        
        def helper(root, depth):
            if not root: return 
            if len(res) == depth:
                res.insert(0,[])
            res[-(depth+1)].append(root.val)
            helper(root.left, depth + 1)
            helper(root.right, depth + 1)
        helper(root, 0)
        return res

```