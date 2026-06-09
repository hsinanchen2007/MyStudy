

```
class Solution(object):
    def minKBitFlips(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """

        n = len(A)
        mask = [0] * (n + 1)
        change = 0
        ret = 0
        for i, x in enumerate(A):
            change ^= mask[i]
            x ^= change
            if x == 0:
                if i + K > n:
                    return -1
                ret += 1
                change ^= 1
                mask[i + K] = 1

        return ret
                
```
