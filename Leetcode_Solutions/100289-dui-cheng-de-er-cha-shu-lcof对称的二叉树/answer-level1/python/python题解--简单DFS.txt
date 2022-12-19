### 解题思路
![image.png](https://pic.leetcode-cn.com/30bfee0f2c1607d6292866d23eb5102ff7a5e7a8c43428ce3a67e78c2c415f98-image.png)
- 镜像也就是左右子树的左右节点值是否相等
- 通过比较即可得出结果

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        def isSyt(left_,right_):
            if not left_ and not right_:#节点都为空,也是对称的
                return True
            elif left_ and right_:#都不为空
                if left_.val != right_.val:#不为空且不相等则不是对称的
                    return False
                else:
                    return isSyt(left_.right, right_.left) and isSyt(left_.left, right_.right)#遍历左右子树
            else:#一个节点为空一个节点不为空
                return False
        return isSyt(root.left, root.right)

            
```