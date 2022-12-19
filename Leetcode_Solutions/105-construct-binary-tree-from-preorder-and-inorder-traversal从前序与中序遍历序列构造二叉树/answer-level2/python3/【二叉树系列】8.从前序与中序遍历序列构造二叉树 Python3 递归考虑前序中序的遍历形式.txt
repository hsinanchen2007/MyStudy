
### 1.相似的一家人
参考：

[从中序和后序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/solution/er-cha-shu-xi-lie-7cong-zhong-xu-yu-hou-xu-bian-li/)


依然是考虑前序遍历：`根左右`，中序遍历：`左根右`
**通过在前序遍历里root的值，去找到在中序遍历中root的index**，由此可以拆分左右子树

```python

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder:
            return
        
        val = preorder[0]
        index = inorder.index(val)
        root = TreeNode(val)
        
        root.left = self.buildTree(preorder[1:index+1], inorder[:index])
        root.right = self.buildTree(preorder[index+1:], inorder[index+1:])
        
        return root
```


![image.png](https://pic.leetcode-cn.com/200ef41dc815a179e999d23c69127faa66b6035887f0c608db3f0e8dd6818317-image.png)
