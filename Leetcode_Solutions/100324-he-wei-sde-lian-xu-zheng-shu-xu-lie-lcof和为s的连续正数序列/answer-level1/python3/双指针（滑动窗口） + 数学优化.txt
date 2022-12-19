class Solution:
    def findContinuousSequence(self, target):
        if target <= 1: return None
        ans = []
        l, h = 1, int((-1 + (1 + 8 * target) ** 0.5) // 2)
        while l < h and h < target:
            sum = (l + h) * (h - l + 1) / 2
            if sum == target: # 注意这种情况指针的移动，比官方的解法更快
                ans.append([i for i in range(l, h + 1)])
                l += 2
                h += 1
            elif sum > target:
                l += 1
            else:
                h += 1
        return ans
