# 看解题思路才弄明白的题 😅


# ```
class Solution(object):
    def diStringMatch(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        left, right, L = 0, len(S), []
        for i in S:
            if i == 'I':
                L.append(left)
                left += 1
            else:
                L.append(right)
                right -= 1
        # 剩下的值无论是left 或 right都是可以满足条件的
        return L + [left]
# ```
