参考了题解里各位大佬的思路，发现了一个比较简单实现的方法，改动后可正常运行，思路就不写了，题解里很详细。


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        def help(preorder, inorder):
            if not preorder:
                return None
            root = TreeNode(preorder[0])
            index = inorder.index(preorder[0])
            root.left = help(preorder[1:index+1], inorder[:index])
            root.right = help(preorder[index+1:], inorder[index+1:])
            return root
        return help(preorder, inorder) if preorder else None