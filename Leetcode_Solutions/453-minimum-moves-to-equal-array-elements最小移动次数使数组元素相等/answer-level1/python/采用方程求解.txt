已知：长度为n的数组nums， 每次移动有n-1个元素增加1
求：数组元素都相等时，最小移动次数x

假设所有元素都相等时数字为k, 如果最小数字经过x次移动能够等于k, 则此时所有元素也能等于k, 此时移动次数为k-min(nums).

则有方程: 数组元素总和增加量 = 终止时数组元素总和 - 开始时数组元素总和

即方程: (k-min(nums)) * (n-1) = k * n - sum(nums)

求解后: k = sum(nums) - min(nums) * (n-1)

则可以得到最小移动次数  k-min(nums)

```Python
class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        min_val = min(nums)
        n = len(nums)
        k = sum(nums) - min_val * (n-1)
        return k - min_val
```