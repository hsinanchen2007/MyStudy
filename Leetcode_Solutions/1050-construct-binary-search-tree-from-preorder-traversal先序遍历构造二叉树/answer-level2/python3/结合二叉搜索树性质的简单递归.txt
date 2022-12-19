```
class Solution:
    def bstFromPreorder(self, preorder: [int]) -> TreeNode:
        
        self.idx = 0
        def build(maximun):
            # 如果当前preorder[idx]大于目前子树中能存在的最大值，说明节点不存在子树
            if self.idx == len(preorder) or preorder[self.idx] >= maximun:
                return None

            root = TreeNode(preorder[self.idx])
            self.idx += 1
            root.left = build(root.val) # 对于左子树来说，其最大值父节点
            root.right = build(maximun) # 对于右子树来说，其最大值为父节点的最大值
            return root
        
        return build(1 << 31)
```