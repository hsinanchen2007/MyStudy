# 难的不是题目本身，而是读题😂
# ```
class Solution:
    def diStringMatch(self, S: str) -> List[int]:
        if not S:
            return []
        l = [x for x in range(len(S)+1)]
        ans =[]
        for i in range(len(S)):
            if S[i] == 'I':
                ans.append(l.pop(0))
            else:
                ans.append(l.pop())
        if S[-1] == 'D':
            ans.append(l.pop(0))
        else:
            ans.append(l.pop())
        return ans
# ```
