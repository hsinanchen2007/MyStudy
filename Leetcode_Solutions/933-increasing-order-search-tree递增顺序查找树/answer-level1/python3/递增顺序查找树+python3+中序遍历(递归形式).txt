### 中序遍历（递归形式）
**(可以参考：[二叉树各种遍历算法](https://www.cnblogs.com/anzhengyu/p/11083568.html))**

先中序遍历得到一个目标数组，再构建新树：
```
class Solution:
    def increasingBST(self, root):
        def inorder(root):
            if not root:
                return []
            else:
                return inorder(root.left)+ [root.val] + inorder(root.right)
        target = inorder(root)
        n = len(target)
        root = TreeNode(target[0])
        head = root
        for i in range(1,n):
            root.right = TreeNode(target[i])
            root = root.right
        return head
```
#### 复杂度分析
__时间复杂度：__ O(n)

__空间复杂度：__ O(n)