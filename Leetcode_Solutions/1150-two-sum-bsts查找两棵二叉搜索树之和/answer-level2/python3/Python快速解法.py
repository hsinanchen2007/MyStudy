### 解题思路
![1581859590(1).png](https://pic.leetcode-cn.com/85e43c97792862e4e67038dd3a29ada3774a566515bbb570f6caf0929d913fd2-1581859590\(1\).png)
先用哈希表存储第一棵树的所有值，而后判断target与第二棵树元素之差是否在哈希表内


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def twoSumBSTs(self, root1: TreeNode, root2: TreeNode, target: int) -> bool:
        tree1 = {}

        def treeVal1(root):
            if root:
                tree1[root.val] = 1
                if root.left:
                    treeVal1(root.left)
                if root.right:
                    treeVal1(root.right)

        treeVal1(root1)

        def treeJudge2(root):
            if root:
                return (target - root.val in tree1) or\
                treeJudge2(root.left) or treeJudge2(root.right)
            else:
                return False

        return treeJudge2(root2)
```