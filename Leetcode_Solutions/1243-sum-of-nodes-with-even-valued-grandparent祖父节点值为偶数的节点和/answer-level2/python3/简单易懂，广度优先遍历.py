（1）为根节点创建虚拟父结点和祖父节点的值分别为1和1；
（2）使用队列，首先存储根节点的信息[node,father,gfather]=[root,1,1]，意思就是当前节点为root，其父亲节点值为1，祖父节点值为1；这样避免了根节点没有父结点和祖父节点的问题；
（3）维护一个变量total保存最终的返回值；遍历队列，当队列中的元素的祖父节点值为偶数时，使用total对数值进行累加计算；
（4）对于该结点的左子节点或右子节点，将其信息放进队列中。其信息表示为[root.left,root.val,root.father]，其中root.left是当前节点的左子节点，root.val是当前节点的值，也是root.left的父结点的值，root.father是当前节点的父结点的值，同时也是root.left的祖父节点值。

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        if not root:
            return 0

        queue = collections.deque([[root,1,3]])  # 创建队列

        total = 0
        while queue:
            node,father,gfather = queue.popleft()

            if gfather%2 == 0:    # 判断祖父节点值是否为偶数
                total += node.val

            if node.left:
                queue.append([node.left,node.val,father])
            if node.right:
                queue.append([node.right,node.val,father])
        return total
```
