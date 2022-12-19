### 方法一: 递归

### 代码

```python
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root == None:
            return None
        root.right, root.left = self.invertTree(root.left), self.invertTree(root.right) 
        return root
```
### 方法二: 迭代

```python
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root == None: return None
        queue = [] # 用队列来存储节点
        queue.append(root) #首先放入父节点
        while queue: # 当队列不为空时
            cur = queue.pop(0)  # 将第一个元素弹出
            cur.left, cur.right = cur.right, cur.left # 将第一个元素的子节点左右交换
            if cur.left: queue.append(cur.left) # 如果第一个元素的左右子节点不为 None, 将其加入队列
            if cur.right: queue.append(cur.right)
        return root
# 所以实际上通过循环, 树会按层被加入队列,然后从上之下交换左右节点
```