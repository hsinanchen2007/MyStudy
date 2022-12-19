抄的官方答案，事后诸葛亮地来解释一下这个方法,(*^▽^*)(*^▽^*)
二叉树的深度 = max(左子树深度，右子树深度) + 1 （这个1是根节点）
不管是左子树还是右子树，它的深度仍然是 max(左子树深度，右子树深度) + 1 （这个1就是该子树的根节点）
所以可以用递归方法求解
边界情况为没有根结点时，层数为0

```
class Solution():
    def maxDepth(self, root):
        if root is None:
            return 0
        left_height = self.maxDepth(root.left)  # 左子树的最大深度
        right_height = self.maxDepth(root.right) # 右子树的最大深度
        return max(left_height, right_height) + 1      # 深度加上根节点
```
