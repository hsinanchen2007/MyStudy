### 解题思路
双指针，不需要特殊处理！

### 代码

```python3
class Solution:
    def largeGroupPositions(self, S: str) -> List[List[int]]:
        if not S:
            return 

        size = len(S)
        left = 0
        right = 1
        res=[]
        while right < size:
            while right < size and S[right] == S[right - 1]:
                right += 1
            if right - left >= 3:
                res.append([left, right-1])
            left = right
            right += 1
        return res

```