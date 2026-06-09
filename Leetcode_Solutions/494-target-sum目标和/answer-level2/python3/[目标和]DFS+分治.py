看到这种第一时间想到的是`DFS`,按照常规思路写的,顺便加一点简单的剪枝方法.

剪枝的思路就是对于当前的序列和,如果加上后面剩下的序列和仍不能达到`S`或者剪掉后面序列和仍超过`S`,那么就返回.

```
class Solution:
    
    def __init__(self):
        self.res = 0

    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        def backtrace(nums, cur_sum, start):
            if start == size:
                if cur_sum == S:
                    self.res += 1
                return
            if cur_sum + postsum[start] < S or cur_sum - postsum[start] > S:
                return
            else:
                backtrace(nums, cur_sum + nums[start], start + 1)
                backtrace(nums, cur_sum - nums[start], start + 1)

        if not nums:
            return 0
        size = len(nums)
        postsum = [nums[-1]] * size
        for i in range(size - 2, -1, -1):
            postsum[i] = postsum[i + 1] + nums[i]
        backtrace(nums, 0, 0)
        self.res = min(2 ** 31 - 1, self.res)
        return self.res
```
结果毫不意外,超时了...  `37 / 139` 个通过测试用例.

随后记录了下剪枝的情况,以`[20,48,33,16,19,44,14,31,42,34,38,32,27,7,22,22,48,18,48,39]
1`为例子,探索了大概400000个可能的空间,得到了5000个左右的结果,说明剪枝的效果还不够.

随后想到是否是数组排序的问题,重排序数组`nums.sort(reverse=True)`的效果明显优于`nums.sort()`,从400000缩减到了130000左右,但是还是超时,不过这次到了`80 / 139`个通过测试用例.

既然规模还是太大,那么就缩减问题规模,突然想到如果分成两个子问题,每个子问题只有`2^10`个空间,这样规模就会明显缩小.

首先就是将nums分解为两个,即`nums[:mid]`与`nums[mid:]`,对两个数组分别做DFS并将所得可能结果分别存入字典,此时问题就化解为字典中数据求和的问题.

```
class Solution:
    
    def __init__(self):
        import collections
        self.res = 0
        self.p1 = collections.defaultdict(int)
        self.p2 = collections.defaultdict(int)

    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        def backtrace(nums, cur_sum, start, part):
            if start == len(nums):
                if part == 0:
                    self.p1[cur_sum] += 1
                else:
                    self.p2[cur_sum] += 1
                return
            else:
                backtrace(nums, cur_sum + nums[start], start + 1, part)
                backtrace(nums, cur_sum - nums[start], start + 1, part)
        if not nums:
            return 0
        size = len(nums)
        mid = size >> 1
        backtrace(nums[:mid], 0, 0, 0)
        backtrace(nums[mid:], 0, 0, 1)
        for val in self.p1.keys():
            if self.p2.get(S - val, False):
                self.res += self.p2[S-val] * self.p1[val]
        return self.res
```
最终,`172ms, 15MB`通过了...