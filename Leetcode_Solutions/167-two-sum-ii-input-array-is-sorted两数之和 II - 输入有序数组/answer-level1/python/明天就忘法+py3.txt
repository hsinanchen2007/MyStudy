### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n=len(numbers)
        l=0
        r=n-1
        while l<r:
            c=numbers[l]+numbers[r]
            if target==c:
                return [l+1,r+1]
            elif target<c:
                r-=1
            else:
                l+=1
        return 
```