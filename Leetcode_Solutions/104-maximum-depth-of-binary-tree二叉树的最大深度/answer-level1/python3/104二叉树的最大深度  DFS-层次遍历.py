### 解题思路
思路和111二叉树的最小深度相同，可以用层次遍历和DFS。

### 代码 --DFS（根节点+max(左子树最大深度，右子树最大深度)）

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        def hasChild(x):
            return x.left or x.right
        def DFS(x):#最大深度
            #递归基：
            if not x: return 0#空节点的深度为0
            if not hasChild(x):return 1#叶子节点的深度为1
            depthMaxL=-float("Inf")#初始化左子树最大值
            depthMaxR=-float("Inf")#初始化右子树最大值
            if x.left:#左子树存在
                depthMaxL=max(DFS(x.left),depthMaxL)#更新左子树深度最大值
            if x.right:#右子树存在
                depthMaxR=max(DFS(x.right),depthMaxR)#更新右子树深度最大值
            return max(depthMaxL,depthMaxR)+1#返回左子树深度最大值和右子树深度最大值中的较大者加上根节点
        return DFS(root)


```