### 解题思路
1. 迭代，主要是需要记录所有的val值
2. 递归，递归的出口还是没有子节点和值==sum_

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum_: int) -> List[List[int]]:
        # ans = list()
        # if not root:
        #     return ans
        
        # de = [(root, [root.val])]
        # while de:
        #     node, tmp = de.pop()
        #     if not node.right and not node.left and sum(tmp) == sum_:
        #         ans.append(tmp)
        #     if node.right:
        #         de.append((node.right, tmp + [node.right.val]))
        #     if node.left:
        #         de.append((node.left, tmp + [node.left.val]))
        # return ans

        ans = list()
        def helper(root, tmp, sum_):
            if not root:
                return 
            if not root.left and not root.right and sum_ - root.val == 0:
                tmp += [root.val]
                ans.append(tmp)
            helper(root.left, tmp + [root.val], sum_ - root.val)
            helper(root.right, tmp + [root.val], sum_ - root.val)
        helper(root, [], sum_)
        return ans
```