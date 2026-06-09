### 解题思路
最长上升子序列，最简单的方式就是 o(n**2) 的动规。
dp[i] 代表以第 i 个箱子放在最底下的最大高度。

### 代码

```python3
class Solution:
    def pileBox(self, box: List[List[int]]) -> int:
        dp = [0 for _ in range(len(box))]
        box.sort()

        for i in range(len(box)):
            dp[i] = box[i][2]
            for j in range(i):
                if box[j][0] < box[i][0] and box[j][1] < box[i][1] and box[j][2] < box[i][2]:
                    dp[i] = max(dp[i], dp[j] + box[i][2])
        return max(dp)
```