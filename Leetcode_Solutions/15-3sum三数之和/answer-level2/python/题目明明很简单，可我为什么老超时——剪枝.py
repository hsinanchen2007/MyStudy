解题思路：先排序，然后从0-n遍历一遍，为一个值找到另外两个值，使它们相加等于0。相当于做n次的双指针。
    这个解题思路想必很多人都想到了。可是提交总会超时。
    特别是python提交的情况下。这题给python的时间不够多。同样的解法，用其他高效的语言能通过，换成python提交就会超时。
这时候就需要使用到剪枝。尽可能的去掉重复计算的部分。

首先双指针中左指针的起点只要从i+1，不必从0出发，因为0-i，之前已经匹配过了。
其次如果你是数列是递增排序，那么当nums[i] > 0时就不必在查找了。因为i+1 到 n-1的值势必都是大于0的，三个大于0的数相加不可能等于0
然后当 i > 0时，nums[i-1] == nums[i]，可以直接跳过。因为题目中提到了，不要重复值。
最后当搜索到满足条件值的时候，不要急着找下一个值。先检查下，nums[l + 1] == nums[l] 和 nums[r - 1] == nums[r]，即左边（右边）相邻的两个数是否相等，如果是，就可以跳过，在检查下一个相邻值是否相等，一直找到不相等的。因为我们不要重复值。这样又可以跳过许多次检查。避免使用复杂的数据结构（比如set）进行去重。
`
    def f(self, nums):
        i, n = 0, len(nums)
        if n < 3:
            return []
        nums.sort()
        print nums
        if nums[0] > 0 or nums[n - 1] < 0:
            return []

        answer = []
        while i < n:
            if nums[i] > 0:
                break
            if i > 0 and nums[i] == nums[i-1]:
                i += 1
                continue
            l = i + 1
            r = n - 1
            while l < r and nums[r] >= 0:
                c = nums[i] + nums[l] + nums[r]
                if c == 0:
                    answer.append([nums[i], nums[l], nums[r]])
                    while l < r and nums[l + 1] == nums[l]:
                        l += 1
                    while l < r and nums[r - 1] == nums[r]:
                        r -= 1
                    l += 1
                    r -= 1
                elif c > 0:
                    r -= 1
                else:
                    l += 1

            i += 1
        return answer`