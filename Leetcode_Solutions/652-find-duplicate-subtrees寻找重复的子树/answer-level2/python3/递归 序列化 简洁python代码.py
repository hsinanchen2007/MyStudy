序列化，递归
```
from collections import defaultdict
class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        m = defaultdict(set) # 默认词典
        def ser(root: TreeNode): # 序列化
            s = f'{root.val}{ser(root.left)}{ser(root.right)}' if root else ' '
            m[s].add(root) # 添加
            return s
        ser(root)
        rs = [v.pop() for v in m.values() if len(v) > 1] # 大于一个节点
        return rs
```
