## 思路：

做这道题， 先把树的中序遍历的迭代写法了解一下

[94. 二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/) | [题解链接](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/die-dai-he-di-gui-by-powcai)

对，这道题就是用**栈**解决，模拟中序遍历过程！

```python
class BSTIterator:

    def __init__(self, root: TreeNode):
        self.stack = []
        self.push_stack(root)

    def next(self) -> int:
        """
        @return the next smallest number
        """
        tmp = self.stack.pop()
        if tmp.right:
            self.push_stack(tmp.right)
        return tmp.val
        
        

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return bool(self.stack)
        
    def push_stack(self, node):
        while node:
            self.stack.append(node)
            node = node.left
```

