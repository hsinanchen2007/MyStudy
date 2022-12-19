### 解题思路
广度优先搜索，创建两个`queue` (用`Python`的`list.pop(0)`来实现，数据少时无需调用`queue`)，轮流用来存每一层的`node`，遍历完每一层之后，两个`queue`交换。也可以通过记录每一层的`node`的数量来判断何时分层，这样用一个`queue`就可以了

### 代码

```python
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root: return []
        q, s = [root], []
        res = []
        while q:
            level = []
            while q:
                node = q.pop(0)
                level.append(node.val)
                s.extend(node.children)
            q, s = s, q
            res.append(level)
        return res
```