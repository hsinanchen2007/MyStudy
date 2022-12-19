```python
class Solution:
    def splitIntoFibonacci(self, S: str) -> List[int]:
        # F[i] + F[i + 1] == F[i + 2]
        # Time complexity : O(N ** 2)
        # Space complexity : O(N)
        
        ans = []
        def check(pre1, pre2, index): #O(N)
            cur = str(pre1 + pre2)
            if int(cur) > 2 ** 31 - 1: return False
            if index + len(cur) > len(S) or S[index: index + len(cur)] != cur:
                return False
            else:
                if index + len(cur) == len(S):  return True
                return check(pre2, int(cur), index + len(cur))

        def length_check(s):
            if len(s) > 1 and s[0] == '0': return False
            return True

        for i in range(1, len(S) - 1): # O(N)
            for j in range(i + 1, len(S)): #O(N)
                pre1, pre2 = S[:i], S[i: j]
                if not length_check(pre1) or not length_check(pre2): continue
                pre1, pre2 = int(pre1), int(pre2)
                if check(pre1, pre2, j):
                    l = len(S[:i]) + len(S[i: j])
                    ans = [pre1, pre2]
                    while l < len(S):
                        cur = pre1 + pre2
                        ans.append(cur)
                        l += len(str(cur))
                        pre1, pre2 = pre2, cur
                    return ans
        return []
```