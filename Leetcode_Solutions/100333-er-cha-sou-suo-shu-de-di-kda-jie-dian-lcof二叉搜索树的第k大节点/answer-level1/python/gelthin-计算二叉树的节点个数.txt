### 解题思路
这一题没有提到二叉搜索树是否有可能有相同值的节点。
如果有相同值，可能存在一些问题，比如前序+中序唯一确定二叉树，是否仍然成立

我这里算法思想是：
+ 计算出右子树的长度
+ 判断第 k 大节点是否在右子树，当前root处，左子树
+ 递归对右子树，左子树处理， 这里非常像二分法。
+ 注意递归退出条件


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:

        def length(root):
            if root == None:
                return 0
            l1 = length(root.right)
            l2 = length(root.left)
            return l1+l2+1
        ## 后序遍历从大到小，第1大，第2大
        if root == None:
            return None
        l1 = length(root.right)
        if l1+1 == k:
            return root.val
        elif l1+1<k:
            return self.kthLargest(root.left, k-l1-1)
        elif l1+1>k:
            return self.kthLargest(root.right, k)
        ## 考虑如果 k 超过了数组的长度怎么办？ 就是返回 None 了，root.left =None, 但是 k-l1-1>0
```