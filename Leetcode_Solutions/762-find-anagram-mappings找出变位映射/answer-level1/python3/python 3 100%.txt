```
class Solution:
    def anagramMappings(self, A: List[int], B: List[int]) -> List[int]:
        ans =[]
        for i in A:
            ans.append(B.index(i))
        
        return ans
```
