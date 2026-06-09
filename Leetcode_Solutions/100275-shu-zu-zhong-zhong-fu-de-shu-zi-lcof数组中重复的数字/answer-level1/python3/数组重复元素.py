小白只想到一种解法，望大神指正。
哈希表解法，遍历数组，存在哈希表中，
```
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        hash = {}
        for i in nums:
            if not i in hash:
                hash[i] = 1
            else:
                hash[i] += 1
        return (list(hash.keys()))[list(hash.values()).index(max(hash.values()))]
```
