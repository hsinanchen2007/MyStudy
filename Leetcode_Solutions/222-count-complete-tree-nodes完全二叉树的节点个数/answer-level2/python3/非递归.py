## 成绩（2019-06-17）

执行用时 : 120 ms, 在所有Python3提交中击败了85.25%的用户

内存消耗 : 20.9 MB, 在所有Python3提交中击败了75.00%的用户

## 思路

评论区内递归的方法已经很多了，然后看到另一位大佬的思路用到了完全二叉树的性质

[评论链接](https://leetcode-cn.com/problems/count-complete-tree-nodes/comments/93206)

*完全二叉树的节点数是空节点数-1*，熟悉《算法导论》的应该看到过这个课后证明题（好像是课后吧）

对于最简单的例子，对于有`n`层的满二叉树（根节点算第一层），其节点数为$2^n-1$个，第`i`层的节点数为$2^{i-1}$个，而其潜在的空节点（也就是第`n+1`层）有$2^n$个，刚好是树的节点数+1，换句话说，树的节点数是空节点-1.

推广到一般例子，在`n`层的满二叉树的基础上（节点数$2^n-1$，空节点$2^n$），生长一个节点，则节点数+1，空节点数-1然后+2，结果还是+1；这就保障了空节点数是节点数+1的关系。

## Python实现

### 利用性质

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def countNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        def search_none(root):
            if not root:
                return 1
            else:
                return search_none(root.left) + search_none(root.right)
        return search_none(root)-1
```

相比这位老哥写的[递归](https://leetcode-cn.com/problems/count-complete-tree-nodes/comments/101178)要快上一些

