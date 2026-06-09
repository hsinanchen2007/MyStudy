```
class Solution:
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:
        if d == 1:
            new_root = TreeNode(v)
            new_root.left = root
            return new_root
        queue = [root]
        deep = 0
        while queue:
            deep += 1
            tmp = []
            for node in queue:
                if deep == d - 1:
                    if node.left:
                        left = node.left
                        new_ = TreeNode(v)
                        node.left = new_
                        new_.left = left
                    else:
                        node.left = TreeNode(v)
                    if node.right:
                        right = node.right
                        new_ = TreeNode(v)
                        node.right = new_
                        new_.right = right
                    else:
                        node.right = TreeNode(v)
                else:
                    if node.left:
                        tmp.append(node.left)
                    if node.right:
                        tmp.append(node.right)
            if deep == d - 1:
                break
            queue = tmp
        return root
```
