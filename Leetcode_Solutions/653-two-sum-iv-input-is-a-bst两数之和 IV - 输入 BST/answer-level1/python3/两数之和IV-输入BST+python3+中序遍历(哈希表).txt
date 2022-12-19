### 中序遍历
**(可以参考：[二叉树各种遍历算法](https://www.cnblogs.com/anzhengyu/p/11083568.html))**

先中序遍历，得到一个目标数组，再通过哈希表判断是否符合要求。代码如下：
```
class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        def inorder(root):
            if not root:
                return []
            return inorder(root.left)+[root.val]+inorder(root.right)
        target = inorder(root)
        n = len(target)
        
        # 创建哈希表
        _dict = {}
        for i, m in enumerate(target):
            if _dict.get(k - m) is not None:
                return True
            _dict[m] = i

        return False

```
#### 复杂度分析
__时间复杂度：__ O(n)

__空间复杂度：__ O(n)