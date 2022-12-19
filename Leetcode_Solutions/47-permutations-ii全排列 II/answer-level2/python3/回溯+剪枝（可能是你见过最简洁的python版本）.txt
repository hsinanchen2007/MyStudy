这里有借鉴：
 1. [@powcai](/u/powcai/) 在46题的解答，大佬用 nums[:i] + nums[i+1:] 巧妙避开了重复利用的问题。
 2. [@liweiwei1419](/u/liweiwei1419/) 在本题的回答,用nums[i]==nums[i-1]，进行剪枝。
 代码如下
```python
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort() # 数组先排序
        self.res = []
        self.recur(nums,[])
        return self.res

    def recur(self,nums,temp):
        if nums == []:
            self.res.append(temp)
            return
        for i in range(len(nums)):
            if i>0 and nums[i] == nums[i-1]: #每当进入新的构成，先考虑该构成的首字符是否和上一个一样。
                continue
            self.recur(nums[:i]+nums[i+1:],temp+[nums[i]]) #nums[:i]+nums[i+1:] 避免了重复利用。

```
