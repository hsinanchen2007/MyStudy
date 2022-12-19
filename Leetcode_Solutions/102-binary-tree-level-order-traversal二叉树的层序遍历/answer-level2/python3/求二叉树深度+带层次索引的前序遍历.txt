### 解题思路
明确问题：层次遍历二叉树，已数组形势打印输出
解题思路：
    可不是简单的层次遍历，一维输出
    需要体现深度，层次
    先求出二叉树高度
    再前序遍历，带上层次的索引

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        depth = self.get_depth(root)
        res = [[] for i in range(depth)]
        self.fill(res,root,0)
        return res

    def fill(self,res,root,depth_index):
        if not root:return
        res[depth_index].append(root.val)
        self.fill(res,root.left,depth_index+1)
        self.fill(res,root.right,depth_index+1)

    def get_depth(self,root):
        if not root:return 0
        return max(self.get_depth(root.left)+1,self.get_depth(root.right)+1)



```