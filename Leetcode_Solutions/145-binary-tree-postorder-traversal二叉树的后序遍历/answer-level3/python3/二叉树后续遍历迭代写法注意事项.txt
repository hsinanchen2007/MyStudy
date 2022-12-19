### 解题思路
后序遍历的递归写法非常容易，跟前序和中序遍历的写法类似，只是最后访问根节点而已。

但是后序遍历的迭代写法则比前序和中序要难一些，主要的问题是根节点必须最后访问才行，这就造成了麻烦。必须非常小心的处理根节点的访问，**考虑何时才能真正访问根节点**。**能访问根节点的情况有两种：1.右子树为空；2.右子树不为空，但已经遍历过了**。右子树是否为空很容易判断，难的是右子树不为空时如何判断是否已经遍历过。因此**必须想办法记录右子树的遍历情况**，可以采用一个额外的节点记录上一次访问的节点，看看是否刚好就是右子树的根节点。

此外，**当右子树不为空时，因为此时要先访问右子树，根节点还不能出栈**，只有当一个节点访问完以后才能出栈。这跟中序遍历不同，中序遍历是到了根节点就可以访问了，所以可以直接将根节点出栈。

除了正常访问节点之外，还可以采用巧妙的方法：**采用先序遍历的方法，同时调换左右子树的访问顺序，最后将得到的结果整个反转**，就能得到跟后序遍历一样的结果。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        if root == None:
            return []

        vals = []
        # recursive version
        # vals.extend(self.postorderTraversal(root.left))
        # vals.extend(self.postorderTraversal(root.right))
        # vals.append(root.val)

        # iterative version
        nodes = []
        node = root
        pre = None  # 记录上一次访问的节点
        while node or nodes:
            while node:
                nodes.append(node)
                node = node.left
            node = nodes[-1]    # 这里不能直接将根节点出栈，因为可能右子树不为空，还不到访问根节点的时候
            if node.right == None or node.right == pre:
                vals.append(node.val)
                nodes.pop() # 节点访问完毕，才将其出栈
                pre = node
                node = None
            else:
                node = node.right

        return vals

```