```
class Solution:
    def jump(self, nums: List[int]) -> int:
        def once(s=0,c=0):
            if s>=len(nums)-1:return c
            elif nums[s] + s>=len(nums)-1:return c+1
            return once(s+[x+k for k,x in enumerate(nums[s+1:s+nums[s]+1])].index(max([x+k for k,x in enumerate(nums[s+1:s+nums[s]+1])]))+1,c+1)
        return once()
```
贪心算法，每次找到能跳最远的位置，出现越过最后或能到最后的情况时返回跳跃次数
另外附上另一个简洁的解题思路（膜拜大神），八行代码，速度打败99%
```
class Solution:
    def jump(self, nums: List[int]) -> int:
        if nums.count(1)==len(nums):return len(nums)-1
        def fun(n):
            if not n:return 0
            for k,v in enumerate(n):
                if v>=len(n)-k:return fun(n[:k])+1
        return fun(nums[:-1])
```
这个的思路是找到第一个能到达最后位置的nums[i]，再找第一个能到达这个位置的nums[k]，递归直到nums[0]，
第三行是为了过一个几百个1的测试用例，所以其实这段代码也是7行解决，而且性能最优。