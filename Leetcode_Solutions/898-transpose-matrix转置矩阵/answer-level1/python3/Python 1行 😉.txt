```python
class Solution:
    def transpose(self, A: List[List[int]]) -> List[List[int]]:
        return [*zip(*A)]
```
- 不用内置函数 ↓
```python
class Solution:
    def transpose(self, A: List[List[int]]) -> List[List[int]]:
        
        def myZip(*arg):
            for i in range(len(arg[0])):
                yield [b[i] for b in arg]
        
        return [*myZip(*A)]
```