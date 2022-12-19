```
class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        S = ''.join(S.upper().split('-'))
        m, n = len(S) % K, len(S) // K
        sl = '-'.join([S[m+i*K:m+(i+1)*K] for i in range(n)])
        if m == 0:
            return sl
        if n == 0:
            return S[:m]
        return S[:m] + '-' + sl

```
