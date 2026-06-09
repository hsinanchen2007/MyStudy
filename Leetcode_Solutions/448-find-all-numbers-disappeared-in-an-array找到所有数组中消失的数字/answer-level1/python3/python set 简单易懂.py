
高赞的答案有点奇淫技巧的意思，不易理解。

我的方法简单易懂，满足“不使用额外空间且时间复杂度为O(n)”  

a这个set因为是答案数组，所以不算在额外空间内,python的for in 语句，是迭代器，所以空间为o(1)，
显然这o(1)的空间是必须的，无论哪个答案都要遍历数组，因此等同于无额外空间。

```
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        a=set(list(range(1,len(nums)+1)))
        for i in nums:
            a.discard(i)
        return a
```
