### 解题思路
思路：令每个节点都能够成为路径的根节点去搜索。
注意：节点值可能为负数，所以每条路径都要从头找到叶子才行。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        visited_set = set([root])
        def get_res(root, temp):
            if root is None:
                return 0
            res = 0
            if temp == root.val:
                res += 1
            # root作为候选路径中间节点
            res += get_res(root.left, temp - root.val) + get_res(root.right, temp - root.val)
            # root作为候选路径根节点
            if root not in visited_set: # 避免根节点重复计算
                visited_set.add(root)
                if root.val == sum:
                    res += 1
                res += get_res(root.left, sum - root.val) + get_res(root.right, sum - root.val)
            return res
        return get_res(root, sum)
            
            
```