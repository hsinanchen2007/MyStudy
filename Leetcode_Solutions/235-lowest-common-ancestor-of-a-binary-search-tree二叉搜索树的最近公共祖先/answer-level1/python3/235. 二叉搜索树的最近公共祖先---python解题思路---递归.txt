## 方法1：递归判断

思路比较简单，由于是二叉搜索树，所以一定有左边小于root，root小于右边，所以当root的值在p，q之间时这个root一定就是答案

```python
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if p.val >= q.val:
            p, q = q, p
        if p.val == root.val:
            return p
        if q.val == root.val:
            return q
        if p.val < root.val < q.val:
            return root
        if q.val < root.val:
            return self.lowestCommonAncestor(root.left, p, q)
        if q.val > root.val:
            return self.lowestCommonAncestor(root.right, p, q)
```

运行结果

```
执行用时 :96 ms, 在所有 Python3 提交中击败了52.14% 的用户
内存消耗 :17.8 MB, 在所有 Python3 提交中击败了6.17%的用户

执行用时 :128 ms, 在所有 Python3 提交中击败了22.50% 的用户
内存消耗 :17.8 MB, 在所有 Python3 提交中击败了6.17%的用户

执行用时 :144 ms, 在所有 Python3 提交中击败了14.17% 的用户
内存消耗 :17.7 MB, 在所有 Python3 提交中击败了6.17%的用户
```



欢迎来github上看更多题目的解答[力扣解题思路](https://github.com/WRAllen/LeetCode)

  