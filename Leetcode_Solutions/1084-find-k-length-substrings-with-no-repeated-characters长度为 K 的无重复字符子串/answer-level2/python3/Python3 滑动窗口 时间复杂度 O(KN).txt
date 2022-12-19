弄个窗口，长度为 K，从 0 开始跑，跑到 len(S) - K + 1。
每次都判断这 K 个元素是否有重复，如果没有就让 Counter 自增 1。
```
class Solution:
    def numKLenSubstrNoRepeats(self, S: str, K: int) -> int:
        if K > len(S) or len(S) == 0:
            return 0
        count = 0
        for p in range(0, len(S) - K + 1):
            c = S[p:p+K]
            p = []
            F = True
            for i in c:
                if i in p:
                    F = False
                    continue
                p.append(i)
            if F: count += 1
        return count
```