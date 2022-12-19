### 解题思路
深度优先遍历，因为先遍历右侧，所以每次能够将右侧的第一时间纳入结果，而题目一个特性就是ans的length是等同于树的深度的所以可以以此来进行判断，若depth小于等于length，则该节点一定是目前这层第一个遍历到的。另外也可以使用层次遍历的方式，然后最后取每一层的最后一位数字即可

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if root==None:
            return []
        self.ans=[]
        def dfs(node,level):
            if node==None:
                return
            if len(self.ans)<=level:
                self.ans.append(node.val)
            dfs(node.right,level+1)
            dfs(node.left,level+1)
        dfs(root,0)

        return self.ans
```