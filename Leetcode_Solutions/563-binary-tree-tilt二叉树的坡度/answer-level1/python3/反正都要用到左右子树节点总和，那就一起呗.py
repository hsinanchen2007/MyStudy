```
class Solution:
    def findTilt(self, root: TreeNode) -> int:
        # 本题与求二叉树直径题目类似，
        # 递归函数是求树的节点和
        # 定义helper函数求以某节点为根节点的树的节点总和，ans+=坡度  即为总坡度
        # 即ans+=helper(左子树)-helper（右子树）的绝对值
        # 而左子树之和加右子树之和加节点值为总树的和，巧妙复用了
        ans=0
        def helper(root):
            nonlocal ans
            if not root:
                return 0
            l=helper(root.left)
            r=helper(root.right)
            ans+=abs(l-r)
            return l+r+root.val
        helper(root)
        return ans
```
