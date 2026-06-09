定义二维dp数组，i，j分别表示当前骰子个数及目标和。
状态转移方程为：dp[i][j] = sum([dp[i-1][k]])， 其中k的范围是 k=[j-骰子最大点数, target-1]

同时i个骰子的最大范围是[i * 1, i * 骰子最大点数]， 故可对target范围进一步缩小。

配合记忆化搜索，可用一行代码实现函数。

```
import functools
class Solution:
    @functools.lru_cache(None)
    def numRollsToTarget(self, d: int, f: int, target: int) -> int:
        return int(sum([self.numRollsToTarget(d-1, f, newtarget) for newtarget in range(max(target-f, 1*(d-1)), min(target, f*(d-1)+1))]) % (1e9+7)) if d else 1
```
