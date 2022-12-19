改造了下UnionFind，因为每次之加入一个元素，所以把union改成add。


```python
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        class UnionFind():
            def __init__(self):
                self.up = {}
            
            def find(self, x):
                if self.up[x] == x:
                    return x
                self.up[x] = self.find(self.up[x])
                return self.up[x]

            def add(self, x):
                self.up[x] = x
                if x - 1 in self.up:
                    self.up[x - 1] = x
                if x + 1 in self.up:
                    self.up[x] = x + 1
            
        uf = UnionFind()
        for num in nums:
            uf.add(num)

        max_l = 0
        for num in nums:
            root = uf.find(num)
            l = root - num + 1
            if l > max_l:
                max_l = l

        return max_l
```
