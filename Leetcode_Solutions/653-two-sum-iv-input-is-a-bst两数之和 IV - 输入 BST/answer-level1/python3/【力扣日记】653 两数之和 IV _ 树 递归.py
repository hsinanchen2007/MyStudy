# 题目描述
给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

# 算法思路
二叉树天然适合递归。
且树为BST：二叉搜索树。
对树使用中序遍历，得到递增序列。

参考[两数之和](https://blog.csdn.net/Heart_for_Ling/article/details/102982115)，使用哈希表：集合，来记录数据并进行`in` 判断。

因为是使用递归，所以当得知结果为True时，修改flag，使得之后的递归可以立即结束。

```python
class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        d=set()
        flag=False
        
        def inord(root):
            nonlocal flag
            nonlocal k
            if flag:return 
            if not root:return 
            inord(root.left)
            if k-root.val in d:flag=True
            d.add(root.val)
            inord(root.right)
        inord(root)
        return flag
```

> 执行用时 :72 ms, 在所有 Python3 提交中击败了98.33%的用户
>内存消耗 :16 MB, 在所有 Python3 提交中击败了5.55%的用户
