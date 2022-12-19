二叉排序树满足左子树<右子树规律，删除结点生成新的二叉树也应满足该规律，删除操作需要特别处理要删除结点前驱和后继问题。为方便说明，假设删除结点为key_node，其前驱为pre_node

#删除结点分为三种情况：
1、左子树为空，右孩子替换key_node，即pre_node后继为key_node.right
2、右子树为空，左孩子替换key_node，即pre_node后继为key_node.left
3、左右子树都非空，首先找到key_node的后继：右子树中最小结点y（该结点特点：左叶子结点，左孩子为空），该结点可保证新的二叉树依然满足排序规则；然后先交换y和key_node.right位置，最后替换y和key_node

结点替换：需特殊处理root结点

```
 def deleteNode(self, root, key):
        """
        :type root: TreeNode
        :type key: int
        :rtype: TreeNode
        """
        if not root:
            return root

        pre_node, key_node = TreeNode(-1), None     # （-1，not None）为删除根结点
        # 查找要删除结点和其父节点       
        node = root
        while node:            
            if node.val == key:
                key_node = node
                break
            else:
                pre_node = node                   
                node = node.left if key<node.val else node.right    
        # 无要删除结点
        if not key_node:
            return root
        # 删除结点
        if key_node.left is None:
            # transplate(pre_node, key_node, key_node.right)
            # 结点替换
            if pre_node.val == -1:
                root = key_node.right
            elif key_node == pre_node.left:
                pre_node.left = key_node.right
            else:
                pre_node.right = key_node.right
            return root

        if key_node.right is None:
            # transplate(pre_node, key_node, key_node.left)
            # 结点替换
            if pre_node.val == -1:
                root = key_node.left
            elif key_node == pre_node.left:
                pre_node.left = key_node.left
            else:
                pre_node.right = key_node.left
            return root 
        
        else:
            y_pre_node = key_node
            y = key_node.right
            # 找后继
            while y.left is not None:
                y_pre_node = y
                y = y.left
            # 处理后继
            if y != key_node.right:
                # transplate(y_pre_node, y, y.right)
                # 结点替换
                if y_pre_node.val == -1:
                    root = y.right
                elif y == y_pre_node.left:
                    y_pre_node.left = y.right
                else:
                    y_pre_node.right = y.right
                
                y.right = key_node.right
            
            # transplate(pre_node, key_node, y)
            # 结点替换
            if pre_node.val == -1:
                root = y
            elif key_node == pre_node.left:
                pre_node.left = y
            else:
                pre_node.right = y

            y.left = key_node.left

            return root
```
