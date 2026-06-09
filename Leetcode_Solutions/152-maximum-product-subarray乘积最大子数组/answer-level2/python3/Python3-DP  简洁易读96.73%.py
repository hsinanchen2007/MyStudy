### 解题思路
1. 本题与53题类似，可以通过DP维护一个位置i之前的最佳值mmax实现O(n)
2. 由于每乘到一个负因子时，最大值会变最小值，最小值会变最大值，因此最大最小状态均需要保存用于后续使用，这里用mmax和mmin记录当前最大连续值与最小连续值
3. 以mmax推导为例，mmax = max(当前因子，mmin*当前因子，mmax*当前因子)
4. mmin = min(当前因子，mmin*当前因子，mmax*当前因子)
4. 使用log记录每个位置的最大连续值mmax

### 代码

```python3
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if len(nums) == 0:return 0
        mmax ,mmin =nums[0],nums[0]
        log = [mmax]
        for i in range(1,len(nums)):
            mmax, mmin = max(nums[i],mmax*nums[i],mmin*nums[i]) ,  min(nums[i],mmax*nums[i],mmin*nums[i])
            log.append(mmax)
        return max(log)

```