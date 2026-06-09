看懂题解后尝试自己捋了下思路
```
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if not nums:
            return None
        n = len(nums)
        if n<2:
            return nums
        def reverse(ind):  
            """
            把nums[ind:]进行翻转
            """
            a, b = ind, n-1
            while a<b:
                nums[a], nums[b] = nums[b], nums[a]
                a += 1
                b -= 1

        for i in range(n-1, 0, -1):
            if nums[i-1]<nums[i]:
                if i==n-1:  
                    # 如果刚好是最后两位则将其换位后输出
                    nums[i-1], nums[i] = nums[i], nums[i-1]
                    return nums
                else:
                    if nums[i-1]<nums[n-1]:
                        # 如果nums[i-1]小于nums[i:]中最小值，则将原最小值换过来，再翻转
                        nums[i-1], nums[n-1] = nums[n-1], nums[i-1]
                        reverse(i) # i begin
                        return nums
                    else:
                        for j in range(i, n):
                            # 如果nums[i-1]后面有更小的，则交换再翻转
                            if nums[i-1]>=nums[j]:
                                nums[i-1], nums[j-1] = nums[j-1], nums[i-1]
                                reverse(i)
                                return nums
        reverse(0)  # 如果是最大的，则翻转成最小的               
        return nums
            





```
