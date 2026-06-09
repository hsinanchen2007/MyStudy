class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:

        # 边界条件判断:（这里实现了，若左右某个子树为空，返回None）
        if not preorder or not inorder:  return None 

        # 初始化根节点
        root = TreeNode(preorder.pop(0))
        index = inorder.index(root.val)

        # 递归，生成左右子树
        left = self.buildTree(preorder, inorder[:index])
        right = self.buildTree(preorder,inorder[index+1:])

        # 分别判断左右子树是否为空
        if left: root.left = left   
        if right: root.right = right
        
        return root;