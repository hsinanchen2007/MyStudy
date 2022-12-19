Python3 思路: 1.先根据key找到对应的节点 2.度为2的节点,需要找到它的后继(前驱也可以)节点, 此时真正删除的节点是前驱或后继节点; 度为1的节点,直接用其子节点代替; 度为0的节点直接把该节点删掉```
Python3

```
class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if root is None: 
            return root
        # 根据key没有找到node
        node, parent = self.findNode(root, key)
         # 如果没找到对应的node, 直接返回
        if node is None: return root
        
        if node.left is not None and node.right is not None:
            # 度为2的节点 需要找到他的后继节点
            successor_node, successor_parent = self.findSuccessorNode(node)
            
            # 将后继节点的值 覆盖当前节点的值
            node.val = successor_node.val
            # 将删除的节点换成后继节点
            node = successor_node
            parent = successor_parent
            
        # 接下来处理度为1 或者度为0的节点
        child = node.left if node.left else node.right
            
        if child is not None:
            # 删除度为1的节点
            if parent is None:
                root = child
            elif node == parent.left:
                parent.left = child
            else:
                parent.right = child
        elif parent is None:
            root = None
        else:
            # 删除度为0的节点
            if node == parent.left:
                parent.left = None
            else:
                parent.right = None
                
        return root

        
    def findNode(self, root: TreeNode, key: int) -> TreeNode:
        """
        根据key找到当前节点
        """
        node = root
        parent = None
        while node is not None:
            if key < node.val:
                parent = node
                node = node.left
            elif key > node.val:
                parent = node
                node = node.right
            else:
                return node, parent
        return None, None
    
    def findSuccessorNode(self, node):
        """
        寻找后继节点 删除后继节点
        这个找后继的方法不严谨  因为node可能没有右子树, 而题目信息我们不知道node的父节点

        """
        parent = node
        node = node.right
        if node:
            while node.left is not None:
                parent = node
                node = node.left
            return node, parent
```
