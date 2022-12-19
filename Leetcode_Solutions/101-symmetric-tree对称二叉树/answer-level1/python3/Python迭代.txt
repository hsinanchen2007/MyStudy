### 代码

```python3
class Solution(object):
    def isSymmetric(self, root):
        if root == None:
            return True
        # 用队列保存节点
        queue = [root,root]
        while queue:
            # 从队列中取出两个节点，再比较这两个节点
            left = queue.pop()
            right = queue.pop()
            # 如果两个节点都为空就继续循环，两者有一个为空就返回false
            if(left == None and right == None):
                continue
            if(left == None or right == None):
                return False
            if left.val!=right.val:
                return False
            # 将左节点的左孩子， 右节点的右孩子放入队列
            queue.append(left.left)
            queue.append(right.right)
            # 将左节点的右孩子，右节点的左孩子放入队列
            queue.append(left.right)
            queue.append(right.left)
        return True
```