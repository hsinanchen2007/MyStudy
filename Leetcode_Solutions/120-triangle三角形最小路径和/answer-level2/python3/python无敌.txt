### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        import sys
        arr = triangle
        l = len(arr)
        new_arr = [[sys.maxsize if i!=0 or j!=0 else 0  for j in range(l+1) ] for i in range(l+1)]
        for i in range(1,l+1):
            for j in range(1,i+1):
                new_arr[i][j]=min(new_arr[i-1][j],new_arr[i-1][j-1])+arr[i-1][j-1]
        return min(new_arr[-1])
```