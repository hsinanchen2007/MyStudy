### 解题思路
有两种思想:递归与循环.
递归:参照递归的4个步骤:1.确定函数功能;2.递推公式,重要,只要把想出来了,就成功了一半;3.终止条件,通过举例子方式归纳得到.4.时空复杂度. 详见代码注释

循环:方法一:可以通过两个list交替循环,这个比较通用,比如计算树深度,打印树等任务.
方法二:通过一个stack的pop操作来实现循环.


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # 函数功能:输入一个root/sum,判断是否存在
    # 递推公式:hasPathSum(root,sum) = hasPathSum(root.left,sum-root.val) or hasPathSum(root.left,sum-root.val)
    # 终止条件:if not root: return False;if 是叶节点 and 值等于sum,return True
    # 复杂度: O(N);O(logN)
    # 只遍历左子树,右子树
    # def hasPathSum(self, root: TreeNode, sum: int) -> bool:
    #         if not root:
    #             return False
    #         if not root.left and not root.right and root.val == sum:
    #             return True
    #         left = self.hasPathSum(root.left,sum-root.val)
    #         right = self.hasPathSum(root.right,sum-root.val)
    #         return left or right

    # 循环.通过两个list进行交替
    # def hasPathSum(self,root,sum):
    #     if not root:
    #         return False
    #     curLayerNode = [(root,sum)]
    #     while curLayerNode:
    #         nextLayerNode = []
    #         for (node,val) in curLayerNode:
    #             if not node.left and not node.right and node.val == val:
    #                 return True
    #             if node.left:
    #                 nextLayerNode.append((node.left,val-(node.val)))
    #             if node.right:
    #                 nextLayerNode.append((node.right,val-(node.val)))
    #         curLayerNode = nextLayerNode
    #     return False

    #循环.通过一个stack的pop进行交替
    def hasPathSum(self,root,sum):
        if not root:
            return False
        stack = [(root,sum)]
        while stack:
            node,val = stack.pop()
            if not node.left and not node.right and node.val == val:
                return True
            if node.right:
                stack.append((node.right,val-node.val))
            if node.left:
                stack.append((node.left,val-node.val))
        return False

