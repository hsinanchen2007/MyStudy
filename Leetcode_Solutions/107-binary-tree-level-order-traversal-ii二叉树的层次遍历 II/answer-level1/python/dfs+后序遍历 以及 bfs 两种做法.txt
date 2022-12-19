```
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        ret = []
        if root is None:
            return ret
        else:

            def dfs(root):
                if root is None:
                    return 0
                else:
                    left_height = dfs(root.left)
                    right_height = dfs(root.right)
                    return max(left_height, right_height) + 1

            def postorder(root, depth):
                if root is None:
                    return
                else:
                    postorder(root.left, depth + 1)
                    postorder(root.right, depth + 1)
                    ret[depth].append(root.val)

            depth = dfs(root)
            for i in range(depth):
                ret.append([])
            postorder(root, 0)
            return list(reversed(ret))
```
dfs+后序遍历

```
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        ret = []
        if not root:
            return ret
        else:
            queue = [root]
            depth = -1
            while queue:
                if queue:
                    depth += 1
                    ret.append([])
                length = len(queue)
                for i in range(length):
                    temp = queue.pop(0)
                    if temp:
                        ret[depth].append(temp.val)
                        if temp.left:
                            queue.append(temp.left)
                        if temp.right:
                            queue.append(temp.right)
            return list(reversed(ret))
```
bfs方法

