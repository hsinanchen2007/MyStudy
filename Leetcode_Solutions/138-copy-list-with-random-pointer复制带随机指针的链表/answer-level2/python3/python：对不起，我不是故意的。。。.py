python：我就是这么强，我也不想啊怎么办，好苦恼啊。
```python []
import copy
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        return copy.deepcopy(head)
```