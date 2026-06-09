### 方法一

```python
from collections import deque
class Solution:
    # 方法一，增加一个变量，len_level记录一层节点的数量，一层一层打
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        levels = []
        if not root: return []
        queue = deque([root,])
        while queue:
            # 给新的一层append一个空列表
            levels.append([])
            # 这层的节点个数
            len_level = len(queue)
            # 打印一层
            for _ in range(len_level):
                node = queue.popleft()  # 出队
                levels[-1].append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        return levels
```
### 方法二

```python
    # 方法二（jian指offer）增加2个变量，toBePrinted要打的节点数和nextLevel下一层的节点数
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        res = [[]]
        queue = deque([root])
        i = 0
        toBePrinted = 1
        nextLevel = 0
        while queue:
            # 上一层节点打印完了
            if toBePrinted == 0:
                res.append([]) # 增加一个list
                toBePrinted = nextLevel # 确定要打的节点数
                nextLevel = 0 # 下一层要打的节点数清零
            node = queue.popleft()
            res[-1].append(node.val)
            toBePrinted -= 1 # 打印一个toBePrinted -1

            if node.left:
                queue.append(node.left)
                nextLevel += 1 # 孩子非空，nextLevel 加1    
            if node.right:
                queue.append(node.right)
                nextLevel += 1 ## 孩子非空，nextLevel 加1    

        return res
```
### 方法三：递归
```python
    # 方法三，递归
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        res = []
        def dfs(node, level):
            if not node:return
            # 这句是关键
            # 当发现节点为第level层，而res有len（res）层，即只有第len（res）-1 = level-1层，res增加一个list
            # 例如节点level == 1，而len（res） == 1，即只有第0层
            if len(res) == level:
                res.append([])
            res[level].append(node.val)
            dfs(node.left, level+1)
            dfs(node.right, level+1)
        dfs(root, 0)
        return res
```