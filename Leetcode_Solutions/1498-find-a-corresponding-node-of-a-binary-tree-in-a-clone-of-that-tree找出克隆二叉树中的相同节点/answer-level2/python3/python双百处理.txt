### 解题思路
![1.jpg](https://pic.leetcode-cn.com/995c2e4304a09d4fbc90907d2682fc63b4732b78ae20979ccd74c871b08e2930-1.jpg)
需要理解题目的思路，主要是在cloned中找到跟original中某元素相同的元素。而且两个二叉树是相同的。
所以同时找，只要target在original，就一定在cloned。那具体怎么找呢？
要么本身就是target，要么在左边，要么在右边。
1、如果本身是，直接返回本身
2、如果本身不是，一直递归猜测左边，如果找到，则返回
3、都找不到，一定在右边查找。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def getTargetCopy(self, original, cloned, target):
        """
        :type original: TreeNode
        :type cloned: TreeNode
        :type target: TreeNode
        :rtype: TreeNode
        """
        if not original:return None
        if original == target:return cloned
        left =  self.getTargetCopy(original.left,cloned.left,target)
        if left:return left
        return self.getTargetCopy(original.right,cloned.right,target)


```