```
class Solution(object):
    def repeatedNTimes(self, A):
        # 摩尔投票要求答案是唯一且超过半数(不包括一半)，而此题答案为一半，因此将末尾数单独考虑
        # 若最终答案是末尾数，则直接找到；否则，保证了剩下的数中最终答案超过半数
        n = len(A)
        candidate, cnt = -1, 0
        for i in range(n-1):
            if A[i] == A[-1]:
                return A[i]
            # 若出现两次则直接返回解
            elif A[i] == candidate:
                return A[i]
            elif cnt == 0:
                candidate = A[i]
                cnt = 1
            else:
                cnt -= 1
        return candidate
```
