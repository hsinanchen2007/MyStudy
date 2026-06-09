### 解题思路
思路是之前做的一个很像的题。算直径的话无非就是两种情况：
1、左子树与右子树中最大值加上当前节点返回，这个不是完整路径，还需要累加到返回的节点上。
2、左子树加上右子树加上当前节点，这个是一个完整路径，就是直径计算已经完成。
3、最后统计两种情况最大值

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0

        a,b = self.func(root)
        b.append(a)

        return max(b)-1 


    def func(self,root):
        if not root:
            return 0,[]
        
        result = []
        left,l_r = self.func(root.left)
        right,r_r = self.func(root.right)
        result += l_r
        result += r_r
        result.append(left+right+1)

        return max(left+1,right+1),result


```