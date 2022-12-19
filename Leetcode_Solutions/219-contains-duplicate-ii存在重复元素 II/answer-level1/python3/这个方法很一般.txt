### 解题思路
感觉这种方法还是很笨，首先通过字典唯一key, 将值相同的元素加入一个列表，判断列表重复数大于2的下标，while 循环判断列表中满足的下标

### 代码

```python3
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        count = {}
        for i, n in enumerate(nums):
            count.setdefault(n, [])
            count[n].append(i)
        for val in count.values():
            if len(val) >= 2:
                while val:
                    top = val.pop()
                    for v in val:
                        if abs(v - top) <= k:
                            return True
        return False
```