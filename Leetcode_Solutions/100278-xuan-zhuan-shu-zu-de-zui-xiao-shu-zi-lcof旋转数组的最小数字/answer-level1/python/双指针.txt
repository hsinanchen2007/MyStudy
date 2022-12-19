### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minArray(self, numbers: List[int]) -> int:
        lens = len(numbers)
        p = 0
        q = lens-1
        while q > p:
            if numbers[p] > numbers[q]:
                p = p + 1
            else:
                q = q - 1
        return numbers[q]

```