# 中序遍历
二叉搜索树可以通过中序遍历得到有序数组, 然后遍历数组找到p节点的位置,返回下一个值.

```python
def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
        """ 
        1. 中序遍历
        2. Morris遍历
        """
        # 使用中序遍历全部节点
        def inorder(node: TreeNode) -> list[TreeNode]:
            if not node:
                return []
            elif not (node.left or node.right):
                return [node]
            else:
                return inorder(node.left) + [node] + inorder(node.right)
        inorderList = inorder(root)
        for i in range(len(inorderList)):
            # 注意判断越界
            if inorderList[i] is p and i < len(inorderList) - 1:
                return inorderList[i+1]
        return None
```

中序遍历可以继续剪枝优化,即对应节点一定只存在于该根节点和根节点对应的一颗子树中, 就引出了第二种方法

# Morris遍历
其实这并不是完整的Morris遍历方法. Morris遍历是在根节点深度较深时, 为了避免出现超过递归调用栈的情况而使用的算法, 这里只是借鉴了其思想.

* 比p节点值大的节点中最小的点一定是右子树中最左叶子节点;
* 如果p节点在root的左子树中, 那么一定存在目标节点;
* 如果p节点是root左子树中最右侧节点, 那么结果就是root;

```python
def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
    if root is p:
            right = root.right
            while right and right.left:
                right = right.left
            return right
        elif root.val < p.val:
            return self.inorderSuccessor(root.right, p)
        else:
            return self.inorderSuccessor(root.left, p) or root
                
```