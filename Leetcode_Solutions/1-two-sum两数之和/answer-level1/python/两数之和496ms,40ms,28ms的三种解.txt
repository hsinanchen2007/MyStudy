### 解题思路
使用了切片和try-except减少判断,达到写字节最省事的目的;若使用字典则大大提升了效率
而最后的28ms是舶来研究如何提高运行效率修改了一下,但是还是没12ms,不晓得怎么做到的
### 代码
496ms:
```python
class Solution(object):
    def twoSum(self, nums, target):

        for s,i in enumerate(nums):
            try:
                return [s,nums[ s+1: ].index(target-i)+s+1]
            except:
                pass
```
40ms:
```python
        #40ms--------|
        mm={}
        for s,i in enumerate(nums):
            w = target-i
            try:
                return [mm[w],s]
             except:
                mm[i]=s
```
28ms:
```python
        #28ms-------|
        n = len(nums)
        res = {}
        for i in range(n):
            if nums[i] in res  and  res[nums[i]]==target-nums[i]:
                return [res[nums[i]],i]
            res[nums[i]]=i
        for i in range(n-1):
            d = target-nums[i]
            if d in res and i !=res[d]:
                return [i, res[d]]
```