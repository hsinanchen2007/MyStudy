### 方法一: 递归

### 代码

```python
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if p == None and q == None:
            return True
        if p == None or q == None:
            return False
        if p.val != q.val:
            return False
        left_val = self.isSameTree(p.left, q.left)
        right_val = self.isSameTree(p.right, q.right)
        return left_val and right_val
```
### 方法二: 迭代
通过队列,不断将两个树相对应的节点同时加入队尾, 并同时弹出进行检查,若遇到不符合要求(不相同)则返回 False, 否则就继续加入,继续检查,直到最后.

```python
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        def check(p, q): # 单独一个 check 函数用来检查两个树对应节点的情况
            if p == None and q == None: return True
            if p == None or q == None: return False
            if p.val != q.val: return False
            return True
        
        que = [(p, q)]           # p, q 放入队列
        while que:               # 队列不为空时, 不断从队首弹出元素
            p, q = que.pop(0) 
            if not check(p, q):  # 检查弹出的两个对应节点
                return False
            if p:                # 若通过了检查,则继续将节点的左右节点加入队尾
                que.append((p.left, q.left))    
                que.append((p.right, q.right))
        return True
```