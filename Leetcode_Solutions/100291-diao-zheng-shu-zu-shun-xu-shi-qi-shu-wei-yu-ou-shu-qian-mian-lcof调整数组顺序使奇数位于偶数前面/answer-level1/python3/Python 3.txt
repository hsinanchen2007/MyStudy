### 解题思路
找奇數在找偶數 拼接

### 代码

```python3
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        odd = [each for each in nums if each%2]
        even = [each for each in nums if each%2 == 0]
        return odd+even
```