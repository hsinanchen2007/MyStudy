### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        ret = []
        for i in range(k):
            mid = min(arr)
            ret.append(mid)
            arr.remove(mid)
        return ret

```