### 解题思路
采用中序遍历二叉搜索树，访问节点排序
二叉树的左指针表示为双向链表的前指针
二叉树的右指针表示为双向链表的右指针

将二叉树的左子树看成一个整体，右子树看成一个整体
则左子树的最后一个节点的right指向根节点，根节点的left指向左子树最后一个节点
根节点的right指向右子树的第一个节点，右子树的第一个节点的left指向根节点
循环表：右子树最后一个节点right左子树第一个节点
       左子树第一个节点left指向右子树最后一个节点

后序遍历将二叉树转换成链表，则每次转换时，左右子树已是链表


### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        def convert(left_node, root, right_node):  ## 首为左子树的头节点，尾为右子树的尾节点
            temp_left, temp_right = left_node, right_node
            if not left_node:
                left_node = root           ##当左子树为空时，首则为root
            else:
                while temp_left.right != left_node: ## 当左子树不为空时，寻找左子树最后一个节点
                    temp_left = temp_left.right
                temp_left.right = root  ###左子树与root连接
                root.left = temp_left
            if right_node:          ###当右子树不为空时，将root与则右子树第一个节点连接
                root.right = right_node
                right_node.left = root
                while temp_right.right != right_node: ##寻找右子树最后一个节点
                    temp_right = temp_right.right
            else:          ##当右子树为空时，尾为root
                temp_right = root
            temp_right.right = left_node  ##首位相接（首为左子树的头节点，尾为右子树的尾节点）
            left_node.left = temp_right
            return left_node

        if not root:
            return           
        left_node = self.treeToDoublyList(root.left)  ##得到左子树链表
        right_node = self.treeToDoublyList(root.right) ##得到右子树链表
        return convert(left_node, root, right_node)    ##将二叉树转换为链表
```