第一想到了哈希表，没有想到二分法，看大家都用的二分法，还是贴出我的哈希表方法吧。
```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        hash = {}
        if target not in nums:
            return 0
        for i in nums:
            if i not in hash:
                hash[i] = 1
            else:
                hash[i] += 1
        return hash[target]
```
