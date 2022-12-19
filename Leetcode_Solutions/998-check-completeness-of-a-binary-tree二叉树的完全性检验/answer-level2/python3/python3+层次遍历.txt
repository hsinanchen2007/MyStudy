### 解题思路
先层次遍历，然后判断除去最后一层外，其余各层有没有放满节点，如果存在没有放满节点的层，直接返回False，否则，根据最后一层节点的数量来判断
如果这棵树是一个完全二叉树，那么最后一层的最后一个节点应该是倒数第二层的第a个节点的左节点或是右节点，直接判断这个节点是否符合就行。
![UC截图20191210140336.png](https://pic.leetcode-cn.com/c47400e2dcd1bcfbb6e15688fccf13aa13ed83e125beb880bef9d65790edbd96-UC%E6%88%AA%E5%9B%BE20191210140336.png)


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isCompleteTree(self, root: TreeNode) -> bool:
        res = []
        #层次遍历
        def helper(root, depth):
            if not root: return
            if len(res) == depth:
                res.append([])
            res[depth].append(root)
            helper(root.left, depth + 1)
            helper(root.right, depth + 1)
        #边界条件判断
        if not root or (not root.left and not root.right):
            return True
        helper(root, 0)
        #判断除最后一层外是否都是满节点，如果有不是满节点的层，直接返回False
        for i in range(len(res)-1):
            if len(res[i]) != 2**i:
                return False
        #判断最后一层的最后一个节点应该是倒数第二层的第几个节点的子节点
        a = len(res[-1])//2
        #判断是左子节点还是右子节点
        b = len(res[-1])%2
        #如果a=0，难么最后一个节点应该是倒数第二层第一个节点的左节点
        if a == 0:
            return res[-2][0].left == res[-1][0]
        #否则在判断
        else:
            if b == 0:
                return res[-2][a-1].right == res[-1][-1]
            else:
                return res[-2][a].left == res[-1][-1]
```