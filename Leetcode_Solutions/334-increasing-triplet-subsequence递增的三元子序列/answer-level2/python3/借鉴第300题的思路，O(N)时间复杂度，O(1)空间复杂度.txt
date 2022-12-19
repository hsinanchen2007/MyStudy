这题思路类似300题的进阶解法，第300题要求解最长上升子序列，是一道动态规划的题目，进阶要求时间复杂度为O(NlogN)。
一种很显然的方法是定义状态dp[i]，表示以索引为i的元素为终点时，可构成的最长上升子序列长度，用这种方式求解dp[i]时需要遍历dp[j] (0 <= j < i)，因此时间复杂度为O(N^2)。
```
for i in range(len(nums)):
    for j in range(i):
        if nums[j] < nums[i]:
            dp[i] = max(dp[i], dp[j] + 1)
```
上述方法的问题在于，状态数组dp是无序的，每次更新dp[i]时需要遍历此前的所有元素，为了降低时间复杂度，我们要优化这个查找的过程，如果状态数组有序，就可以采用二分查找，使总的复杂度降低到O(NlogN)。重新定义状态tail[i]，表示长度为i + 1的子序列的尾部元素值最小是多少，此处的想法是一个较小的数值后面更可能接一个比它大的数字。
```
def lengthOfLIS(self, nums: List[int]) -> int:
    if not nums:
        return 0
    size = len(nums)
    tails = [0] * size
    res = 0
    for num in nums:
        i, j = 0, res
        while i < j:
            mid = (i + j) >> 1
            if tails[mid] >= num:
                j = mid
            else:
                i = mid + 1
        tails[i] = num
        if j == res:
            res += 1
    return res
```
回到这题本身，我们只用判断是否存在三元子序列，因此不用定义tail数组，而是用两个变量first, second分别表示长度为1的子序列尾部最小值，长度为2的子序列尾部最小值，遍历nums数组，若当前数字大于second则说明存在三元子序列，返回True即可，否则就对first和second进行更新，使其保持在可能存在的最小值。
```
def increasingTriplet(self, nums: List[int]) -> bool:
    first, second = sys.maxsize, sys.maxsize
    if not nums or len(nums) < 3:
        return False
    for n in nums:
        if n > second:
            return True
        elif n > first:
            second = min(n, second)
        else:
            first = n
    return False
```

