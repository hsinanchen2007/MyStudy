### 解题思路
（1）需要定义一个sum_cur 来记录当前结点对应的二进制和，ans来表示最终的总和
（2）遇到叶子结点时，ans+=sum_cur,最终返回ans
 (3) 寻求递归关系，当前结点的二进制和=上一结点的二进制和*2+当前结点的值
### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumRootToLeaf(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ans,sum_cur=0,0
        if not root:
            return root
        def sumHelper(root,sum_cur):
            if not root:
                return
            sum_cur=sum_cur*2+root.val
            if not root.left and not root.right:
                self.ans+=sum_cur
            sumHelper(root.left,sum_cur)
            sumHelper(root.right,sum_cur)
        sumHelper(root,0)
        return self.ans
```