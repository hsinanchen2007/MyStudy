这道题用中序遍历很容易求解，但时间复杂度是N，抛弃了BST查询速度的优势

BST的性质
当前节点val < 当前节点右孩子子树最左侧叶子val < 所属最直接左子树的根节点val < 该根节点的右子树最左侧叶子val

思路就很清楚了
1. 先找到对应节点，并将路径上的节点入栈
2. 找右孩子的最左叶子，如果为NULL，进入下一步
3. 找到所属的最小左子树的根节点
```
    def inorderSuccessor(self, root, p):
        if root is None: return None
        def findRightMin(node):
            current = node.right
            if current is None: return None
            while current.left: current = current.left;
            return current

        path = []
        node = root
        while node is not None and node.val != p.val:
            if p.val < node.val:
                path.append(node)
                node = node.left
            else:
                path.append(node)
                node = node.right

        if node is not None:
            # 要么在右子树的最左侧
            # 要么在上方（作为左子树）
            rightMin = findRightMin(node)            
            leaf = node
            while rightMin is None and len(path) > 0:
                top = path.pop();
                if (leaf != top.right):
                    rightMin = top
                leaf = top       
            return rightMin
        return None
```
