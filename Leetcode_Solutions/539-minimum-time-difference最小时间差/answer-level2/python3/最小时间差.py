### 解题思路
大佬@tuotuoli的代码；自己的思路也是这样，但错在没钾1440：为啥d[0]要+1440？

1440 = 24 * 60

### 代码

```python3
class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        d = set()
        for c in timePoints:
            k = int(c[: 2]) * 60 + int(c[3: ])
            if k in d:  #可能快在了判重这里
                return 0
            d.add(k)
        d = sorted(d)
        d.append(d[0]+1440)  # 为啥要+1440
        return min(d[i] - d[i - 1] for i in range(1, len(d)))

# 作者：tuotuoli

```