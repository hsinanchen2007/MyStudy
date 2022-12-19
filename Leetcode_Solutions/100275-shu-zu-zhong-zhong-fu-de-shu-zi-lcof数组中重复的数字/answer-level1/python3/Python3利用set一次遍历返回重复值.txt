```
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        res_set = set() 
        # 通过set的方法，一次遍历就找出结果 O(n)
        for num in nums:
            if num not in res_set:
                res_set.add(num)
            else:
                return num
```
