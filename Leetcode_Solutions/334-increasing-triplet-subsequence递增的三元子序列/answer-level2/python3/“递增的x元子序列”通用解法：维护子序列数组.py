 # “递增的x元子序列”通用解法：维护子序列数组

首先是本题题解：
维护一个子序列数组win，该数组长度最长为3。初始化win为[nums[0]]，随后遍历数组。
1. 遇到比子序列最后一位大的元素，则可以将其加入子序列中
2. 若比子序列最后一位要小，则需要更新该子序列，使得子序列“尽量小”，例如子序列为[1,4]时，此时遇到元素2，那么需要将子序列更新为[1,2]，因为在子序列“尽量小”的情况下才更容易遇到递增元素；另一个例子是[4, 5], 遇到元素1,此时需要更新为[1,5]，可以发现这时候子序列并不严格对应最终的递增子序列，但是在只需要长度的情况下可以不用考虑子序列的元素情况。

空间复杂度：O(1) 最长为3的子序列数组
时间复杂度：O(n) , 子序列数组可以看做为常数数组

```
class Solution:
    def increasingTriplet(self, nums: [int]) -> bool:       
        if len(nums) < 3:
            return False

        win = [nums[0]]

        for num in nums:
            if num > win[-1]:
                win.append(num)
                if len(win) >= 3:
                    return True
            else:
                i = len(win) - 1
                while i > 0 and win[i-1] >= num:
                    i -= 1
                
                win[i] = num
        return False
```

# 通用解
通用解只需要修改子序列数组win的长度即可

