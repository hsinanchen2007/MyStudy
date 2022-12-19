双指针，但是如果你直接用nums.reverse()就没意思了

class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        if not s:
            return
        left = 0
        right = len(s) - 1
        while left < right:
            s[right],s[left] = s[left],s[right]
            right -= 1
            left += 1

更多精彩的leetcode答案[点击此处](https://github.com/tcandzq/LeetCode)