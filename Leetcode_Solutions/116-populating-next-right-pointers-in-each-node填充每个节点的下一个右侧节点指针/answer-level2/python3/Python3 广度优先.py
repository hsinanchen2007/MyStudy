### 解题思路
使用广度优先，一层一层遍历。
遍历每一层的时候，将它的孩子加入队列，并将这一层用next连起来

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root
        queue=[root]
        while len(queue)>0:
            # 取出一层
            temp=queue.copy()
            queue=[]
            for i in range(len(temp)-1):
                # 如果有孩子就入队
                if temp[i].left:
                    queue.append(temp[i].left)
                    queue.append(temp[i].right)
                # 用next连起来
                temp[i].next=temp[i+1]
            # 最后一个元素的next连到None
            if temp[-1].left:
                queue.append(temp[-1].left)
                queue.append(temp[-1].right)
            temp[-1].next=None
        return root
        
```