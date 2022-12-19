![屏幕快照 2020-02-05 下午2.35.53.png](https://pic.leetcode-cn.com/7a78b6f15498654883a7234822ad1d0f662c841ca49e2b4f2ff5bff0790d88f6-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-05%20%E4%B8%8B%E5%8D%882.35.53.png)

首先两数相加的问题可以用一个字典将时间复杂度从O(n**2)降低到O(n)

```python
def two_sum(nums):
    hash_map = {}
    result = []
    for num in nums:
        # key为value需要找的那个数字
        if num in hash_map:
            result.append([hash_map[num], num])
        hash_map[-num] = num
    return result
```

对于三个数的情况，可以固定一个数字，即可转换为两数之和的问题

```python
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if not nums or len(nums)<3:
            return []
        n = len(nums)
        result = []
        nums_set = set(nums)
        for i in range(0, n):
            x = nums[i]
            the_sum = -x
            hash_map = {}
            # 变成求两数相加，和为the_sum的问题
            for j in range(i+1, n):
                y = nums[j]
                if y in hash_map:
                    result.append([x,hash_map[y],y])
                    continue
                hash_map[the_sum-y] = y
        return result
```

可是这样还是会有重复解，需要有一个机制避免重复

先看对于题干例子nums = [-1, 0, 1, 2, -1, -4]，使用上面的代码会得到

```
[[-1,0,1],[-1,2,-1],[0,1,-1]]
```

[0,1,-1]与[-1,0,1]重复了，重复的原因是-1这个值出现了两次，第一次它在位置一（x），第二次它在位置三（z）。

因此，我们要做的事情就是让重复的值不出现在不同的位置

根据我们的算法，让重复的值聚集起来的方法是排序，排序后，每次移动x的时候，都让它跳过重复的值，然后，在处理两数之和的时候，同一个y，只能匹配一个z，即在字典中将匹配过的key值置为None，不可再重复匹配这个key。

这样，即可保证不会出现重复的结果

```
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if not nums or len(nums)<3:
            return []
        n = len(nums)
        nums.sort()
        result = []
        for i in range(0, n):
            x = nums[i]
            # 排序后，最左边的值必须是负数或0（[0,0,0]）才可能使三数只和等于0
            if x > 0:
                return result
            # 跳过重复的值
            if i > 0 and nums[i-1] == x:
                continue
            the_sum = -x
            hash_map = {}
            # 变成求两数相加，和为the_sum的问题
            for j in range(i+1, n):
                y = nums[j]
                if y in hash_map:
                    if hash_map[y] is not None:
                        result.append([x,y,hash_map[y]])
                        hash_map[y] = None
                    continue
                hash_map[the_sum-y] = y
        return result
```
