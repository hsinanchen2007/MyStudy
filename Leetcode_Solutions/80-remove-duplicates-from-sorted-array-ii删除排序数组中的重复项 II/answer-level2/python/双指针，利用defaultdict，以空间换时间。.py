### 解题思路
我利用了一个知识点defaultdict（还有counter也很好用），可以很清楚的判断我是否已经有两个相同的元素，我牺牲了空间换取时间。代码可能较为冗余，第一次写题，解大家一起加油啊！

### 代码

```python
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        from collections import defaultdict
        lookup = defaultdict(int)

        n = len(nums)
        p = 0
        q = 1
        if n <= 2:
            return n
        lookup[nums[p]] += 1
        while q <= n-1:
            if nums[p]==nums[q]:
            
                if lookup[nums[q]] >= 2:
                    q += 1
                else:
                    lookup[nums[q]] += 1
                    nums[p + 1] = nums[q]
                    p += 1
                    q +=1
            else :

               
                lookup[nums[q]] += 1
                nums[p+1] = nums[q]
                p += 1
                q += 1
      
        return p+1
```