### 解题思路
这题主要是要想清楚x+y>y+x 这样去排序

### 代码

```python3
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        result = ''.join(sorted(map(str, nums), key=Tool))
        return "0" if result[0] == '0' else result

class Tool(str):
    def __lt__(x, y):
        return x+y>y+x
```