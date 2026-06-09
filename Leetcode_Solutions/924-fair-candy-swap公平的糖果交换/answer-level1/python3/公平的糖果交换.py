### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        sumA = sum(A) 
        sumB = sum(B)
        setB = set(B)
        for x in A:
            if (x + (sumB - sumA) / 2) in setB:
                return [x, x + (sumB - sumA) // 2]
        
       
```