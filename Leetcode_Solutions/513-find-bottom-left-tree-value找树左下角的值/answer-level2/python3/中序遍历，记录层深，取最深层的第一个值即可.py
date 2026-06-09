准备一个字典，key为层深，value为该层节点值
中序遍历时，记录层深
取最深层第一个节点值即可

```python
from collections import defaultdict
class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        height_dict = defaultdict(list)
        def helper(node, now):
            if not node:
                return now
            left = helper(node.left, now+1)
            height_dict[now].append(node.val)
            right = helper(node.right, now+1)
        helper(root, 0)
        return height_dict[max(height_dict.keys())][0]
```