```
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        # BFS 广度优先层次遍历   存储最右边的值
        ret = []
        queue = collections.deque()
        if root == None: return []
        queue.append(root)

        while queue:
            temp = []
            for _ in range(len(queue)):
                node = queue.popleft()
                temp.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            ret.append(temp[len(temp)-1])
        return ret
```
