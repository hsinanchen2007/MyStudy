### 解题思路
![Capture.PNG](https://pic.leetcode-cn.com/fa08ae5253ca6b3e5ef0a54dd57b48e1e64fc13b6b74601a68daf1f0b1f7dbad-Capture.PNG)
此处撰写解题思路

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        sumOfpoint = lambda x, y: x//10 + x % 10 + y//10 + y % 10
        s = set()
        def pathSearch(x, y):
            if (x+1, y) not in s and sumOfpoint(x+1, y) <= k and x+1 < m : #right
                s.add((x+1, y))
                rdep = pathSearch(x+1, y)
            else:
                rdep = 0
            if (x, y+1) not in s and sumOfpoint(x, y+1) <= k and y+1 < n: #botton
                s.add((x, y+1))
                bdep = pathSearch(x, y+1)
            else:
                bdep = 0
            return rdep + bdep + 1
        return pathSearch(0, 0)
```