### 解题思路
需要注意的是，有可能元素是重复的。

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]: 
        result = []
        maxnum = 0
        if k == 0:
            return result

        if k >= len(arr):
            return arr

        result = arr[:k]
        maxnum = max(result)

        for i in arr[k:]:
            if i < maxnum:
                result.remove(maxnum)
                result.append(i)
                maxnum = max(result)
        return result
```