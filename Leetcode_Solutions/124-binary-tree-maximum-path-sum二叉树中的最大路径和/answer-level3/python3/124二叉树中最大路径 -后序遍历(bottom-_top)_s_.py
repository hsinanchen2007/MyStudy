### 解题思路
从底向上递归：DFS(**后序遍历**)
#### 思路
每次递归，**记录**当前节点与左右子树组成的最大值(`max_sum=max(root.val+left+right,max_sum)`)，并**返回**当前节点与左右子树的较大者的和(保证深入到路径最大的分支搜索))(`root.val+max(left,right)`)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    #路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
    def maxPathSum(self, root: TreeNode) -> int:
        if not root:return 0
        pr=[]
        max_sum=float('-Inf')
        def DFS(root):#当前节点的最大路径和(后序遍历) 
            nonlocal max_sum
            left,right = 0,0
            if root.left:left = max(DFS(root.left),0)#左子树的最大路径和，最小为0
            if root.right:right  = max(DFS(root.right),0)#右子树的最大路径和，最小为0
            max_sum=max(root.val+left+right,max_sum)#更新当前节点最大值
            return root.val+max(left,right)#返回此节点与左右子树的最大值，较小值舍弃
            
        DFS(root)
        return max_sum
```