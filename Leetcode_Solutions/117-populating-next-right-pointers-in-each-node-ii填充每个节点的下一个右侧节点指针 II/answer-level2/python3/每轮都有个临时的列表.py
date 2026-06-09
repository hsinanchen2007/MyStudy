和上一题用同一套代码解决的，但是运行时间不太美丽，220ms。每轮迭代都存下当前节点的左右孩子，说是队列，但是我没有deque操作

```python []
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:    return None
        if not root.left and not root.right:    return root
        que = [root]
        while que:
            next_level = []
            if len(que)>1:
                for q in range(len(que)-1):
                    que[q].next = que[q+1]
                    if que[q].left: next_level.append(que[q].left)
                    if que[q].right:    next_level.append(que[q].right)
            if que[-1].left:    next_level.append(que[-1].left)
            if que[-1].right:   next_level.append(que[-1].right)
            que = next_level
        return root
```


