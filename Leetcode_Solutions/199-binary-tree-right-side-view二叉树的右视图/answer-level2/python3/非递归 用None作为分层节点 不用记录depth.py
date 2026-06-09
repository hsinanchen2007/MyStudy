
```
from collections import deque
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        rs = [] # 结果
        queue = deque() # 队列
        queue.append(root) # 添加第一个元素
        queue.append(None) # 添加层次的分隔符
        prev = None # 记录上一次访问的节点
        while queue:
            p = queue.popleft() # 出队
            if p and p.left: # 处理左子节点
                queue.append(p.left)
            if p and p.right: # 处理右子节点
                queue.append(p.right)
            if not p and not prev: # 连续2个None，结束
                break
            if not p: # 处理层结束
                rs.append(prev.val) # 输出
                queue.append(None) # 加新的一层标记
            prev = p
        return rs
```
