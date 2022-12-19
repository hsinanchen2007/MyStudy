### 解题思路
#计算每一个节点的左右子树的最大深度,同时取左右子树的最大深度之和的最大值为答案.
### 代码
```
class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ret = 0;
        def fun(root):
            if not root:
                return 0
            d1,d2 = fun(root.left),fun(root.right)
            self.ret = max(d1+d2,self.ret)
            return max(d1,d2)+1
        fun(root)
        return self.ret
```