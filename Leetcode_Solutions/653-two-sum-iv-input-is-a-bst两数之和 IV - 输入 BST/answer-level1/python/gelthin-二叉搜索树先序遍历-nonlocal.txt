### 解题思路
+ 使用 nonlocal 变量 pre_l 把二叉搜索树的先序遍历结果存储下来
+ 然后再对 pre_l 有序数组进行查找。这里为什么查找不会漏解一定要想清楚，例如 2,3,4,5,6,7 查找 8
+ 关于 nonlocal 的用法参见 [105. 从前序与中序遍历序列构造二叉树 gelthin-复习python global-nonlocal](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/gelthin-fu-xi-python-global-nonlocal-by-gelthin/)

当然还有其他办法，我没有去测试。



### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        def preorder(root):
            if root == None:
                return 
            nonlocal pre_l 
            preorder(root.left)
            pre_l.append(root.val)
            preorder(root.right)
        if root == None:
            return False
        pre_l = []
        preorder(root)
        i, j = 0, len(pre_l)-1
        while i<j:
            if pre_l[i] + pre_l[j] == k:
                return True
            elif pre_l[i] + pre_l[j] < k:
                i += 1
            else:
                j -= 1
        return False


```