### 解题思路
遍历是否为9，是9变0，不是9返回即可

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        for i in range(1,len(digits)+1):
            if digits[-i] != 9:
                digits[-i] += 1
                return digits
            digits[-i] = 0
        digits.insert(0,1)
        return digits
```