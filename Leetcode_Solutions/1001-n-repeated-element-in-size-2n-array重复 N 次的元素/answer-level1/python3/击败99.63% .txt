### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        N = len(A)//2
        dict = {}
        for j in A:
            dict[j] = dict[j] + 1 if dict.get(j) else 1
            if dict[j] > 1:
                return j 
        

        
```