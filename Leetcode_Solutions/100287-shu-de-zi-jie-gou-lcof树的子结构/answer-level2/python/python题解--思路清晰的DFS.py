### DFS
![image.png](https://pic.leetcode-cn.com/8f06a4a0518cc8a57e86e83f84e7683ee606b91261e7b3dca9258e9709787880-image.png)
- 算法思路(剑指offer):
1. 第一步:在树`A`中找到和树`B`的根节点的值一样的节点`R`;
2. 第二步:判断树`A`中以`R`为根节点的子树是不是包含和树`B`一样的结构
--------------------------------------------------------------------------------------------------------------------
- 详细步骤:
1. 第一步:在树`A`中查找与根节点的值一样的节点,这实际上就是树的遍历,可以使用递归或者循环实现,这个应该没什么问题,代码也有注释
2. 第二步:判断树`A`中以`R`为根节点的子树是不是包含和树`B`一样的结构.同样我们使用递归来考虑:
- 如果节点`R`的值和树`B`的根节点不相同,则以`R`为根节点的子树和树`B`肯定不具有相同的节点
- 如果节点`R`的值和树`B`的根节点相同,则递归的判断他们各自左右节点的值是不是相同.递归的终止条件是达到了树`A`或者树`B`的叶节点

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSubStructure(self, A, B):
        """
        :type A: TreeNode
        :type B: TreeNode
        :rtype: bool
        """
        result = False
        if  A and  B:#A和B都不为空
            if A.val == B.val:
                result = self.isSubTree(A, B)#递归的判断他们各自左右节点的值是不是相同
            if not result:
                result = self.isSubStructure(A.left, B)#不相等则将树A的左子树与B进行比较
            if not result:
                result = self.isSubStructure(A.right, B)#不相等则将树A的右子树与B进行比较
        return result

    def isSubTree(self, root_A, root_B):
        if not root_B:#如果B为空,说明前面的节点都能一一对应上了,所以B是A的子树
            return True
        if not root_A:#如果A为空,则说明B不是他的子树
            return False
        if root_A.val != root_B.val:#节点值不相等,说明也不是
            return False
        # 判断左右子树是否符合
        return self.isSubTree(root_A.left, root_B.left) and self.isSubTree(root_A.right, root_B.right)


                







```