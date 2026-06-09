### 解题思路

语言优势改用就用

### 代码

```python []
class Solution:
    def swapNumbers(self, numbers: List[int]) -> List[int]:
        return numbers[:: -1]
```