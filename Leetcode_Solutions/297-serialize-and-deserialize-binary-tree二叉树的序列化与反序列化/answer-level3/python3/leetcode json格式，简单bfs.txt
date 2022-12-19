```python
from collections import deque
import json

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        r = []
        q = deque()
        q.append(root)
        while len(q) > 0:
            root = q.popleft()
            if root:
                q.append(root.left)
                q.append(root.right)
                r.append(root.val)
            else:
                r.append(None)
           
        # 清除末尾多余的none
        while len(r) > 0 and r[-1] is None:
            r.pop()
        
        return json.dumps(r)



    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        
        l = json.loads(data)
        
        if len(l) == 0:
            return None

        head = TreeNode(l[0])
        root = head
        idx = 0
        q = deque() # 存放父节点的队列
        q.append(root)
        while len(q) > 0:
            root = q.popleft()
            left = None
            idx += 1
            if idx < len(l) and l[idx] is not None:
                left = TreeNode(l[idx])
                q.append(left)

            right = None
            idx += 1
            if idx < len(l) and l[idx] is not None:
                right = TreeNode(l[idx])
                q.append(right)

            root.left = left
            root.right = right
        return head
```

结合leetcode的格式说明，代码还是比较清晰的。