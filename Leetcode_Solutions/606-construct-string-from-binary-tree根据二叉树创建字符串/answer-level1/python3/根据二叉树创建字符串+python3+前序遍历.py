### 前序遍历
**(可以参考：[二叉树各种遍历算法](https://www.cnblogs.com/anzhengyu/p/11083568.html))**

主要注意的地方是如何把括号加进去以及哪些空括号不影响映射关系需要去掉（左右皆空或者只有右子树是空）。代码如下：
```
class Solution:
    def tree2str(self, t: TreeNode) -> str:
        def preorder(root):
            if not root:
                return ''
            if not root.left and root.right:  #左边为空右边不为空的时需要加一个空括号保证映射关系
                return str(root.val)+'()'+'('+preorder(root.right)+')'
            if root.left and not root.right:
                return str(root.val)+'('+preorder(root.left)+')'
            if not root.left and not root.right:
                return str(root.val)
            return str(root.val) + '('+preorder(root.left)+')'+'('+preorder(root.right)+')'
        return preorder(t)
```
#### 复杂度分析
__时间复杂度：__ O(n)

__空间复杂度：__  O(n)

看评论改了一个更简单的版本，时空复杂度表现更好：
```
class Solution:
    def tree2str(self, t: TreeNode) -> str:
        if not t:
            return ''
        left = '('+self.tree2str(t.left)+')' if (t.left or t.right) else ''
        right = '('+self.tree2str(t.right)+')' if t.right else ''
        return str(t.val) +left + right
```