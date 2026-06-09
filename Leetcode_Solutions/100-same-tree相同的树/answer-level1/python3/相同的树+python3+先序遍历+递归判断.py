### 1.  先序遍历
**(可以参考：[二叉树各种遍历算法](https://www.cnblogs.com/anzhengyu/p/11083568.html))**

先序遍历，返回目标数组，判断是否相等。代码如下：
```
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        def preorder(root):
            if not root:
                return [None]
            else:
                return [root.val] +preorder(root.left)+preorder(root.right)
        return preorder(p)==preorder(q)
```
#### 复杂度分析
__时间复杂度：__ O(n)

__空间复杂度：__ O(n)

### 2.  递归判断
判断当前两个节点的值是否相等，再递归的判断两个树的左右子树是否分别相等。代码如下：
```
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if not p and not q:
            return True
        elif p and q:
            return p.val == q.val and self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right)
        else:
            return False
```
#### 复杂度分析
__时间复杂度：__ O(n)

__空间复杂度：__ O(n)