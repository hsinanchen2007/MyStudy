```
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root == None:
            return None
        if root.left == None and root.right == None:
            return root
        stack = []
        stack.append(root)

        while stack:
            node = stack.pop()
            if node:
                temp = node.left
                node.left = node.right
                node.right = temp
                if node.left:
                    stack.append(node.left)
                if node.right:
                    stack.append(node.right)
        return root
```
不多说了，一看就懂，用栈模拟递归。
![image.png](https://pic.leetcode-cn.com/89bf1f30982481a2bdf9ca9b07cdc6fdabab188078905c9c5152e83b846a7c24-image.png)



