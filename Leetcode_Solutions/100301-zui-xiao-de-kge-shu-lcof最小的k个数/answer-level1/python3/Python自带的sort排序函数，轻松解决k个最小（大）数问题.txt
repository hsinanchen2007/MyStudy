### 解题思路
Python中有自带排序函数，只需将所给数列按从小到大排序，之后输出前k个数即可。

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if not 0<=k<=len(arr)<=10000:
            return 0
        arr.sort()
        ans=arr[:k]
        return ans
```