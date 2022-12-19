```python
from typing import List
class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        class Union:
            def __init__(self, n):
                self.cnt = n
                self.parent = [i for i in range(n)]
                
            def find(self, p):
                while p != self.parent[p]:
                    self.parent[p] = self.parent[self.parent[p]]
                    p = self.parent[p]
                return p
            
            def union(self, a, b):
                a_root = self.find(a)
                b_root = self.find(b)
                if a_root == b_root: return
                if a_root < b_root:
                    self.parent[b_root] = a_root
                else:
                    self.parent[a_root] = b_root
                self.cnt -= 1    

            def get_count(self):
                return self.cnt
            
        ut = Union(len(M))
        for i in range(len(M)):
            for j in range(len(M[0])):
                if M[i][j] == 1:
                    ut.union(i, j)
    
        return ut.get_count()
```