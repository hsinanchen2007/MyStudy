1. 解出来了 但是不够简洁

```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def bstFromPreorder(self, preorder):
        """
        :type preorder: List[int]
        :rtype: TreeNode
        """
        if preorder is not None:
            # 将root节点先创建
            root = TreeNode(preorder[0])

            self.i = 1
            while(self.i < len(preorder)):
              self.construct(preorder[self.i], root)
            return root
                
    def construct(self, val, root):
        # 需要判断, 数值插在左子树还是右子树
        if root is not None:
            # 左子树
            if val < root.val:
                # 结点不为空 说明该位置已经有值 需要再往下面找可插入位置
                if root.left is not None:
                    # _root_data.left
                    self.construct(val, root.left)
                else:
                    root.left = TreeNode(val)
                    self.i +=1
                    
            # 右子树
            else:
                if root.right is not None:
                    # _root_data.right 作为新节点判断
                    self.construct(val, root.right)
                else:
                    root.right = TreeNode(val)
                    self.i +=1
        else:
            root = TreeNode(val)
      
"""
1. preorder是一个list [8,5,1,7,10,12], 首先需要去构建这个树, 按照先序遍历方法
2. 构建条件为
   - 默认L[0]位置为root.val
   - L[1] < L[0] 构建左子树 否则 构建右子树
   - L[2] root.left.left 创建
   - L[3] root.left.right 创建
   - L[4] root.right 创建
"""
```

2. 优化内容
"""
(1) 确定root.val = L[0]
(2) 如果没有该节点, 则创建个节点
(3) 划分战队, 是left, right 左右子树哪儿边 
    规则为 小于L[0] 在left, 大于L[0]在right边
(4) 第一次划分为 left = [5,1,7] right = [10, 12]

(5) [5,1,7]作为root.left新list, [10, 12]作为root.right新list
    递归调用 因为是先序遍历, 所以list中第一个一定新的node节点值
    [5,1,7]再次分为 为left = [1] right = [7]
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        if len(preorder) > 0:
            root = TreeNode(preorder[0])
            Left, Right = [], []

            for val in preorder[1:]:
                if val < preorder[0]:
                    Left.append(val)
                else:
                    Right.append(val)
                
            root.left = self.bstFromPreorder(Left)
            root.right = self.bstFromPreorder(Right)
            return root