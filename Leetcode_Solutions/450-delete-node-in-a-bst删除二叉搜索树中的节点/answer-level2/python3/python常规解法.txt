讨论多种分支，代码还是复杂了点。但是挺快的
![image.png](https://pic.leetcode-cn.com/02633356a4e5395586dcbe649342e481778b15871155baa2b0ebf5a4eb61ff5a-image.png)

```python
class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        # 删除节点返回新的子树    
        def delete(node):
            # 没有子节点，返回None
            if not node.left and not node.right:return None
            # 没有左子节点，返回右子节点
            elif not node.left:return node.right
            # 没有右子节点，返回左子节点
            elif not node.right:return node.left
            # 待删除节点度为2，详细讨论
            else:
                # 左子节点没有右子节点
                if not node.left.right:
                    node.left.right=node.right
                    return node.left
                # 右子节点没有左子节点
                elif not node.left.right:
                    node.left.right=node.right
                    return node.left 
                # 都不满足，返回左子树最大值
                else:
                    # 记录父节点pre
                    pre=left=node.left
                    while left.right:
                        pre=left
                        left=left.right
                    # 保存待最大值的左子树到父节点的右子树
                    pre.right=left.left
                    left.left=node.left
                    left.right=node.right
                    return left
        
        if not root:return root        
        if root.val==key:
            root=delete(root)
            return root
        # 标志位记录待删除结点是左子节点还是右子节点
        f=0
        father=node=root
        while node.val!=key:
            if node.val>key:
                father=node
                node=node.left
                f=0
            else:
                father=node
                node=node.right
                f=1
            if not node:return root
        if f==0:father.left=delete(node)
        else: father.right=delete(node)
        return root
```
