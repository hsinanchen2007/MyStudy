```python []
class Solution:
    def productExceptSelf(self, nums):
        nums_rev=reversed(nums)
        a,b,la,lb=1,1,[],[]
        for i,j in zip(nums,nums_rev):
            la.append(a)
            a*=i
            lb.append(b)
            b*=j
        lb.reverse()
        return [i*j for i,j in zip(la,lb)]
```

