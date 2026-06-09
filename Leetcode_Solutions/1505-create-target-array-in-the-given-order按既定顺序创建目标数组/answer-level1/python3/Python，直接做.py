只需要几行代码。。没有 get 到这道题要考察什么。

```python
class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        target = []
        for n, i in zip(nums, index):
            target = target[:i] + [n] + target[i:]
        return target
```
