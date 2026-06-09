### 解题思路
此处撰写解题思路

### 代码

```python3
import re


class Solution:
    def myAtoi(self, str: str) -> int:
        nums = re.match(r"\s*(([+-][0-9]+)|([0-9]*))", str)
        result = nums.group()
        result = result.strip().lstrip("0")
        if not result:
            return 0
        result = int(result)
        min_value = -2 ** 31
        max_value = -min_value - 1
        if result < min_value:
            return min_value
        if result > max_value:
            return max_value
        return result

```