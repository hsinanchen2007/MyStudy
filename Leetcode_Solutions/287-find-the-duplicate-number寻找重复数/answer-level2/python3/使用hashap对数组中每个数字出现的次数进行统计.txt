只能使用额外的 O(1) 的空间。这里不符合要求
```
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        hashmap={}
        for num in nums:
            if num in hashmap:
                hashmap[num] += 1
            else:
                hashmap[num] = 1
        return list(filter(lambda x:x[1]>1, hashmap.items()))[0][0]
```
