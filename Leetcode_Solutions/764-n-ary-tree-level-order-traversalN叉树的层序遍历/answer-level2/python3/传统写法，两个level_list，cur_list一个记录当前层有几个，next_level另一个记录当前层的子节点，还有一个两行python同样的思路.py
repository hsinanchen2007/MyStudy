### 解题思路
这个就是nested for loop
for r in d:
    for t in r.children:
缩写版
    d = [t for r in d for t in r.children]
```
d = root and [root]
while d:
    yield [r.val for r in d]
    d = [t for r in d for t in r.children]
```

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
class Solution:
    # def levelOrder(self, root: 'Node') -> List[List[int]]:

    #     if root is None:
    #         return [root]

    #     level = [root]
    #     res = []

    #     while level:
    #         cur_nodes = []
    #         next_level =[]

    #         for node in level:
    #             cur_nodes.append(node.val)
    #             if node.children: next_level += node.children
                    
    #         res.append(cur_nodes)
    #         level = next_level
            
    #     return res


    def levelOrder(self, root: 'Node') -> List[List[int]]:
            d = root and [root]
            while d:
                yield [r.val for r in d]
                d = [t for r in d for t in r.children]
```