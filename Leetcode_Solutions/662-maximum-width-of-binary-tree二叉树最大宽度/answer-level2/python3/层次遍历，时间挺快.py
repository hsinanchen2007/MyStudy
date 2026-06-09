- 给所有节点标号，根节点为0
- `左子节点编号 = 父节点编号 * 2 + 1`
- `右子节点编号 = 父节点编号 * 2 + 2`

- 编号和节点一起入队列，按层遍历
- `每层的宽度 = 队列末尾节点对应编号 - 队列开头节点对应编号 + 1`
- 每一次产生下一层之前，更新最大宽度

```
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        queue = [(root, 0)]
        result = 0
        while queue:
            result = max(result, queue[-1][1] - queue[0][1] + 1)
            qLen = len(queue)
            while qLen:
                qLen -= 1
                (node, no) = queue.pop(0)
                if node.left:
                    queue.append((node.left, 2*no + 1))
                if node.right:
                    queue.append((node.right, 2*no + 2))
        
        return result
```
