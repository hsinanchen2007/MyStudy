### 解题思路
执行用时 :160 ms, 在所有 Python3 提交中击败了94.45%的用户
内存消耗 :14.8 MB, 在所有 Python3 提交中击败了5.26%的用户

思路：
如果每次都计算sum(nums[: i]) == sum(nums[i+1:])，最后执行用时在8740ms左右，很慢。
所以我们将前缀和leftsum和后缀和记录下来，每次只需要计算leftsum+nums[i]和right-nums[i]即可。
另外注意，i得0的时候，前面没元素，leftsum和rightsum第一次比较之前不计算leftsum；同理，leftsum和rightsum最后一次比较之后，不计算rightsum。因此，先算rightsum，在比较，在算leftsum。
也可以不记录rightsum，每次计算rightsum = S-leftsum-value。

### 代码

```python3
class Solution(object):
    def pivotIndex(self, nums):
        rightsum = sum(nums)
        leftsum = 0
        for i, value in enumerate(nums):
            rightsum -= value
            if leftsum == rightsum:
                return i
            leftsum += value
        return -1
            
```