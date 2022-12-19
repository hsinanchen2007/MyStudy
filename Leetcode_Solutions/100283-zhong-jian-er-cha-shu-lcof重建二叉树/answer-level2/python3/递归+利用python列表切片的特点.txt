### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
      if not preorder:
        return None
      tree_val = preorder[0]
      tree =TreeNode(tree_val)
      index = inorder.index(tree_val)
      lp,li,rp,ri = [],[],[],[]
      ######切片，可以自己尝试一下
![批注 2020-03-08 160545.png](https://pic.leetcode-cn.com/785cc47d61e403abb24be9189e1a8ce5043315726a0464242e8bb3dabf5d8506-%E6%89%B9%E6%B3%A8%202020-03-08%20160545.png)
      li,ri = inorder[0:index],inorder[index+1:]
      lp,rp = preorder[1:index+1],preorder[index+1:]
              
      tree.left = self.buildTree(lp,li)
      tree.right = self.buildTree(rp,ri)
      return tree
```