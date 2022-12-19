### 解题思路
实际是考察查找算法。。。

### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        dic = collections.Counter(nums)
        times = dic.get(target)
        if times == None:
            return 0
        else:
            return times
```