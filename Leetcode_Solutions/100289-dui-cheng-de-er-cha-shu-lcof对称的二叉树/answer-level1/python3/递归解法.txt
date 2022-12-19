### 解题思路
如果一棵二叉树和它的镜像一样，那么它是对称的。对于一棵二叉树 `t1` 和它的镜像 `t2` 有如下特点：
- 根节点相同
- `t1` 左子树等于 `t2` 的右子树
- `t2` 左子树等于 `t1` 的右子树
因此我们递归调用判断以上三点是否满足即可。
### 代码

```python []
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def isMirror(t1, t2):
            if not t1 and not t2: return True # 如果都为空，则是对称的
            if not t1 or not t2: return False # 如果其中一个为空另一个不是，则不是对称的
            return t1.val == t2.val and isMirror(t1.right,t2.left) and isMirror(t1.left,t2.right)

        return isMirror(root,root)
```
### 复杂度分析
- 时间复杂度：$O(N)$。
- 空间复杂度：$O(N)$。