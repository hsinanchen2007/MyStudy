```
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        
        while len(triangle)>1:
            for i in range(len(triangle[-2])):
                if triangle[-2][i]+triangle[-1][i]<triangle[-2][i]+triangle[-1][i+1]:
                    triangle[-2][i]+=triangle[-1][i]
                else:
                    triangle[-2][i]+=triangle[-1][i+1]
            triangle = triangle[:-1]
            
        return triangle[0][0]
                
```
