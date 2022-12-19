```python
class Solution:
    def largestMultipleOfThree(self, digits: List[int]) -> str:
        d = collections.defaultdict(list)
        for c in digits:
            d[c%3].append(c)
        
        for i in range(3):
            d[i].sort()
        res = ''
        
        ans = sum(digits)
        mod = ans % 3
        if mod == 1:
            if d[1]:
                d[1] = d[1][1:]
            else:
                d[2] = d[2][2:]
        if mod == 2 and d[2]:
            if d[2]:
                d[2] = d[2][1:]
            else:
                d[1] = d[1][2:]
                 
        nums = d[0] + d[1] + d[2]
        nums.sort(reverse=True)
        if not nums:
            return ''
        elif nums[0] == 0:
            return '0'
        else:
            return ''.join([str(i) for i in nums])
        
```
