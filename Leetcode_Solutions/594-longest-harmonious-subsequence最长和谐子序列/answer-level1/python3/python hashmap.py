思路：将元素出现的次数添加至map,O(n)。然后遍历计算相邻元素的累加和的最大值,O(n)。总体复杂度O(n).
```
class Solution:
    def findLHS(self, nums: List[int]) -> int:
        hashmap = {}
        for item in nums:
            if item not in hashmap:
                hashmap[item] = 1
            else:
                hashmap[item] += 1
        res = 0
        for item in hashmap:
            if item+1 in hashmap:
                up = hashmap[item+1] 
                res = max(res,up+hashmap[item])
        return res
```
