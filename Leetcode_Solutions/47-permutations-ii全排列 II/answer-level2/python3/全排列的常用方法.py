主要就俩种思路：

1. 先排序，排列时跳过重复元素，这个应该挺好理解，因为重复元素相互交换等于没有交换。

2. 不排序，排列时用set去重

以下有五段代码
第三段使用递归+set()去重，显然set()使用过于频繁，有很多重复步骤
第五段使用生成式，代码虽短消耗却一如既往的大，这也是生成式不被经常使用的原因
```reasonml
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        # 60ms(97%),13.1MB(90%)
        nums.sort()
        rl = []
        def backTrack(nums=nums, temp=[]):
            if not nums: rl.append(temp); return
            for i in range(len(nums)):
                if i>0 and nums[i]==nums[i-1]:
                    continue
                backTrack(nums[:i]+nums[i+1:], temp+[nums[i]])
        backTrack()
        return rl

        # 68ms(83%),12.8MB(99%)
        import itertools
        return {l for l in itertools.permutations(nums)}
        
        # 394ms(30%),13.1MB(92%)
        rl = set()
        def backTrack(nums=nums, temp=()):
            if not nums: rl.add(temp); return
            for i in range(len(nums)):
                backTrack(nums[:i]+nums[i+1:], temp+(nums[i], ))
        backTrack()
        return rl
        
        # 44ms,12.8MB
        rl = [()]
        for i in range(len(nums)):
            temp = []
            for l in rl:
                for j in range(i+1):
                    temp.append(l[:j]+(nums[i], )+l[j:])
            rl = list(set(temp))
        return rl

        # 140ms,18.3MB
        rl = [()]
        for i in range(len(nums)):
            rl = [l[:j]+(nums[i], )+l[j:] for l in rl for j in range(i+1)]
            rl = list(set(rl))
        return rl
```
注：LeetCode上的排列组合对数据类型没有严格要求，返回{, } or (, ) or [, ]都可以