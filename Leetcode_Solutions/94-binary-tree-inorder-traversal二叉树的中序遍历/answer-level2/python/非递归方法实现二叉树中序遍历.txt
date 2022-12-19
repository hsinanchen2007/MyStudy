二叉树的三种遍历：preorder、inorder、postorder其实是针对根节点描述的。
前序：根--左--右
中序：左--根--右
后续：左--右--根

递归算法就会变得特别简单，借助一个辅助函数traversal：


```
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        self.ret = []
        
        def traversal(root):
            if root.left:
                traversal(root.left)
            self.ret.append(root.val)
            if root.right:
                traversal(root.right)
        
        if not root:
            return []
        
        traversal(root)
        return self.ret
```

非递归算法，略微要理一下思路，借助于一个FIFO或者栈，遍历二叉树，对每一个节点：
1. 压栈
2. 处理左节点（处理方式也是压栈）
3. 如果没有左节点了，则出栈一个节点（最后压入的左节点）
4. 处理出栈的节点（将值加入返回结果列表中）
5. 处理出栈节点的右节点（重复1~4）。

代码大致如下：

```
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        tmpli = []
        ret = []
        
        while root or tmpli:
            while root:
                tmpli.append(root)
                root = root.left
            root = tmpli.pop(-1)
            ret.append(root.val)
            root = root.right

        return ret
```




