### 解题思路
采用中序遍历二叉搜索树，按照从小到大的顺序访问二叉树。用中间量将上一结点与当前结点进行双向连接。得到首尾不相接的双向顺序链表head和逆序链表tail
### 代码

```
class Solution:
    def __init__(self):
        self.pre = None
        self.head = None
        self.tail = None

    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if not root:
            return None
        self.treeList(root)
        #将head与tail连接起来即得完整的双向链表
        self.head.left = self.tail          #head生成一个顺序的双向链表（首尾不相接）
        self.tail.right = self.head         #tail会得到逆序的双向链表（首尾不相接）
        return self.head

    def treeList(self,node):
        if not node:
            return None
        self.treeList(node.left)
        
        if self.pre == None:
            self.head = node
        else: 
            self.pre.right = node
        node.left = self.pre
        self.pre = node
        self.tail = node

        self.treeList(node.right)
```