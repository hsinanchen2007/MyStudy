### 解题思路
此处撰写解题思路

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
    def __init__(self):
        self.head, self.pre = None, None
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if not root:
            return None
        # 二叉搜索树的中序遍历是递增的，因此把标准中序遍历中 改变每个父节点的左右指向即可
        # head, pre, tail = None,None,None # 不是集合，要在def里引用的话得放在__init__(self)里
        def inorder(node=root):
            if node:
                # 中序遍历，先left
                inorder(node.left) 
                # 中序遍历，然后父节点
                if not self.pre:
                    self.head = node #记录初始头节点
                else:
                    self.pre.right, node.left = node, self.pre # 按顺序链接节点
                self.pre = node
                # 中序遍历，最后 right
                inorder(node.right)
        inorder()
        self.head.left, self.pre.right =  self.pre, self.head # 链接首位节点，跳出递归的pre是最后一个节点
        return self.head

```

非递归解法先留个坑...

