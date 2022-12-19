# **思路和105一样**

# **代码：**

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:

        if len(inorder) == 0:
            return None
        # 后序遍历最后一个值为根节点
        root = TreeNode(postorder[-1])
        # 因为没有重复元素，所以可以直接根据值来查找根节点在中序遍历中的位置
        mid = inorder.index(postorder[-1])
        # 构建左子树
        root.left = self.buildTree(inorder[:mid], postorder[:mid])
        # 构建右子树
        root.right = self.buildTree(inorder[mid+1:], postorder[mid:-1])
        
        return root