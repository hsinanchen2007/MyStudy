> 方法都是力扣官方题解的，做了Python化地处理并且做了些许调整。
## 递归
> 参考https://leetcode-cn.com/problems/two-sum/solution/python-di-gui-die-dai-by-knifezhu/
```Python
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        f = self.inorderTraversal
        return f(root.left) + [root.val] + f(root.right) if root else []
```
## 非递归（堆栈）
> 参考评论区
```Python
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res, st, n = [], [], root
        while n or st:
            while n:
                st.append(n)
                n = n.left
            n = st.pop()
            res.append(n.val)
            n = n.right
        return res
```
## 莫里斯遍历
```Python
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res, curr = [], root
        while curr is not None: 
            if curr.left is None:
                res.append(curr.val)
                curr = curr.right
            else: 
                pre = curr.left
                while pre.right is not None: pre = pre.right
                pre.right, curr.left, curr,  = curr, None, curr.left
        return res
```