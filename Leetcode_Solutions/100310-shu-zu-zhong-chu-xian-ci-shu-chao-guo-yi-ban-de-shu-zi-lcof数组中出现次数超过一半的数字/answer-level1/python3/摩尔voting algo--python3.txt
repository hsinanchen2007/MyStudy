### 解题思路
摩尔voting algo, 应该再加一个follow up
面试一般会联考两题把
### 代码
```
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        cur = None

        for i in nums:
            if count == 0: 
                cur = i
            # count += 1 if cur == i else -1
            count += (-1, 1)[cur == i]
        return cur
        
```
