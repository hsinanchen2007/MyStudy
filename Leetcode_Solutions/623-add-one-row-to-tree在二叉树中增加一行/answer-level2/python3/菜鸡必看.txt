### 解题思路
他娘的累死人了

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:
        # 先把目标层的节点找出来
        # 最好在遍历的时候就把事情干了
        # 还得分左右子树
        def helper(root,x,which,v,d) :
            if not root  :
                return 
            # 换个思路 从d-1层开始
            if x==d-1 :
                a=TreeNode(v)
                b=TreeNode(v)
                a.left=root.left
                b.right=root.right
                root.left=a
                root.right=b
            helper(root.left,x+1,1,v,d)
            helper(root.right,x+1,2,v,d)
        if d==1 :
                a=TreeNode(v)
                a.left=root
                return a
        helper(root,1,3,v,d)
        return root
```