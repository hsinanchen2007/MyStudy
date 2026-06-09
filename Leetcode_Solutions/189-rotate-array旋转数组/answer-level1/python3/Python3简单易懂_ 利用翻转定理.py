### 解题思路
总体翻转一次
然后nums[0:k]翻转, nums[k:]翻转, 就是最后结果.
由于不能使用额外空间, 得改在原先的nums上, 只能做原地的交换了.

### 代码

```python3
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if (len(nums) <= 1): return
        nums.reverse()
        k = k % len(nums)
        for i in range(0, k//2):
            nums[i], nums[k-1-i] = nums[k-1-i], nums[i] 
        for i in range(k, (k+len(nums)-1) // 2 + 1):  # 3, 4
            # print(i, len(nums) - 1 - (i - k))
            nums[i], nums[len(nums) - 1 - (i - k)] = nums[len(nums) - 1 - (i - k)], nums[i]

```