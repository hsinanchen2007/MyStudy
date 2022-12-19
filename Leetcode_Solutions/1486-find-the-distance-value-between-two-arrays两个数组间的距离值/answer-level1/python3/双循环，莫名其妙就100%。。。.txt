### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        count=len(arr1)
        for i in arr1:
            for j in arr2:
                if abs(i-j)<=d:
                    count-=1
                    break
                continue
        return count
     
                
            
```