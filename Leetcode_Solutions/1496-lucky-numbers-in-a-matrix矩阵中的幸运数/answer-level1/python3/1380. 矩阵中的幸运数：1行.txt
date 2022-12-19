![image.png](https://pic.leetcode-cn.com/51b559168c1bebc206432bf448b942554e49f0891f4809cb65dc08804ec9b850-image.png)

集合取并

```python []
class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        return [*({*map(min, matrix)} & {*map(max, zip(*matrix))})]
```