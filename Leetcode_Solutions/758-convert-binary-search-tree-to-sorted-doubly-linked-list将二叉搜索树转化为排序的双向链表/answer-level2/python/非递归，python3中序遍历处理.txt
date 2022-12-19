### 解题思路
首先思路是二叉树的中序遍历。当根节点非空时，使用栈保存信息。开始时放入根节点和标记。
标记0表示其左孩子尚未被访问，1表示左孩子已经被访问。在中序遍历中，我们只有处理完左孩子（标记是1）的情况下才能处理当前结点。
这道题与一般中序遍历的区别是，我们需要保存当前已遍历部分的尾结点，和指向第遍历中第一个被访问元素的头结点（或者dummy）。其中，尾结点在代码中用`pre`表示，头结点用`head`表示。尾结点在新加入元素时被使用，而头结点在处理最后一个元素时被使用。


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
        if not root:
            return root
        head = ListNode("head")
        pre = head
        stack = [(root, 0)]
        while stack:
            node, flag = stack.pop()
            if flag == 0:  # left child not visited
                stack.append((node, 1))
                if node.left:
                    stack.append((node.left, 0))
            else: 
                # store the info about right child first
                if node.right:
                    stack.append((node.right, 0))
                # deal with the current node
                # print(node.val)
                pre.right = node
                node.left = pre
                pre = node
        pre.right = head.right
        head.right.left = pre
        return head.right 



```