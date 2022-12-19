### 解题思路
![image.png](https://pic.leetcode-cn.com/e1ae42b90a3d12f4b9fa8958108c9a72ca0a5ac367722599d14fbe283a3d1811-image.png)

- 此题在数据结构书中是当做例题来讲的,属于最基础的题型.
- 给定如下遍历序列:
![image.png](https://pic.leetcode-cn.com/16325ffc0b4aa92e7c2bced0e24973b022df1c469c03ec94d9b9e2f8937c5c0a-image.png)

- 我们需要根据这两个序列划分,我们知道前序遍历的第一个节点为头结点,在这了头结点为`[3]`,我们在中序遍历中找到`[3]`所在的位置,可以看到位于中序遍历的第二个位置,那么我们可以确定`[3]`的左子树的节点包含`[9]`,右子树节点包含`[20,25,7]`,一直这样划分下去,直到数组为空,在返回节点.

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if len(preorder) == 0:
            return None
        #创建当前节点
        node = TreeNode(preorder[0]) 
        #在中序遍历中查找第一个节点的位置
        index = inorder.index(preorder[0]) 
        # 划分左右子树
        left_pre = preorder[1:index+1]
        left_in = inorder[:index]
        right_pre = preorder[index+1:]
        right_in = inorder[index+1:]
        # 遍历创建子树
        node.left = self.buildTree(left_pre, left_in)
        node.right = self.buildTree(right_pre, right_in)
        # 返回当前节点
        return node







```