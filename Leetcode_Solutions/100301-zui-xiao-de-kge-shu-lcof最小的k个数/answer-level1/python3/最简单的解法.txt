### 解题思路
思路：先排序，然后返回k个, 直接调用python系统的函数sort()即可.

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        arr.sort();
        return arr[0:k];
```