想法很简单,通过后序遍历序列的末尾确定当前树的root,查找root在中序遍历序列中的位置,根据这个分割给定序列中哪一部分属于左子树,哪一部分属于右子树.
重新得到子树的中序,后序遍历,递归交给下一层去做.
```
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if not inorder or not postorder: return None
        root = postorder[-1]
        res = TreeNode(root)
        i = inorder.index(root)
        res.left = self.buildTree(inorder[:i],postorder[:i])
        res.right = self.buildTree(inorder[i+1:],postorder[i:len(postorder)-1])
        return res
```
运行速度不是很快,但个人觉得这个思路最直观
其中的查找元素位置可以用别的方法实现