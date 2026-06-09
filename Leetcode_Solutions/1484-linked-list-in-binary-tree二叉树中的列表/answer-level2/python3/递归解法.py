### 解题思路
本题是一个结点匹配的问题，如果第一个结点匹配，那么剩下的交给递归处理验证是否匹配问题即可，因此想到用递归来解决。
#### 算法
递归函数 $helper(head, root)$ 主要分两步解决：
1. 链表的头结点 $head$ 和二叉树中的某个结点 $root$ 匹配；
2. 链表的下一个结点 $head.next$ 与结点 $root.left$ 或 $root.right$ 匹配。（递归）

![1.png](https://pic.leetcode-cn.com/9e0d91502086002f15c5ae445410308222b77d07cca0155a6dcc39223b18de74-1.png)

值得注意的是，如何在递归前首先找到图中第一个匹配的结点 $4$ 呢？这时需要从左右子树寻找与 $head$ 匹配的点，即递归调用原函数 $isSubPath(head, root.left)$ 或 $isSubPath(head, root.right)$。
### 代码

```python []
class Solution:
    def isSubPath(self, head: ListNode, root: TreeNode) -> bool:
        if not root: return False
        return self.helper(head, root) or self.isSubPath(head, root.left) or self.isSubPath(head, root.right) 

    def helper(self, head, root):
        if not head: return True
        if root and root.val != head.val or not root: return False
        return self.helper(head.next, root.left) or self.helper(head.next, root.right)

```