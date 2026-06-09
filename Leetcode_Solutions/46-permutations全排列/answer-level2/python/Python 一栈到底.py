
跑了一次 48 ms(...再跑就60ms左右了)，leetcode-cn 每次跑可能差挺多的，不能当真。
拿掉最左面的，递归，插入最右面，相当于nums转了一圈。
考虑到最简单的case，有三个数的时候，其实也就相当于拿出一个数，另外2个转圈，只要每次拿出不一样的就可以。所以利用 deque 拿出最左侧的，放最右即可。


```python
import collections


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 1:
            return [list(nums)]
        if not hasattr(nums, 'maxlen'):
            nums = collections.deque(nums)
        res, L = [], len(nums)
        for _ in range(L):
            num = nums.popleft()
            res.extend(l + [num] for l in self.permute(nums))
            nums.append(num)
        return res
```