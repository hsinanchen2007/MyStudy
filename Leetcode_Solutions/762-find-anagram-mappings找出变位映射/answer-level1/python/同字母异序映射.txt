### 解题思路
目标是遍历A中每个元素，找出当前探索元素在B中对应的索引，所以用dict，key是B中元素本身，val是元素对应索引

### 代码

```python
class Solution(object):
    def anagramMappings(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        D = {x: i for i, x in enumerate(B)}
        return [D[x] for x in A]
```