假设下标为 `i` 之前的花园已经被全部覆盖, 那么需要覆盖的花园从最左边开始为`[i, i + 1]`. 使用贪心算法, 在覆盖`[i, i+ 1]`的前提下, 选择一个水龙头其最多可以向右覆盖到什么地方. 当 `i >= n`时, 整个花园被全部覆盖. 具体实现思路以及细节见代码

```
class Solution:
    def minTaps(self, n: int, r: List[int]) -> int:
        ans, i, start = 0, 0, 0 # ans: 为最少需要选择的水龙数目, i: 为当前需要覆盖的最左边的位置, start: 为开始选择水龙头的下标, start之前的水龙头不可能会被选取
        while i < n:
            j, maxC = start, i
            while j - i <= 100 and j <= n: # 100 为range[i]的最大值
                if r[j] >=  (j - i) and maxC <= r[j] + j: maxC, start = r[j] + j, j + 1 # r[j] >= (j - i): 表示水龙头j可以覆盖到i, maxC <= r[j] + j: 表示该水龙头覆盖到最右地方,大于当前选择的水龙头
                j = j + 1
            if maxC == i: return -1 # 无法向右覆盖, 即没有办法全覆盖, 返回-1
            ans = ans + 1 # 选择start - 1的水龙头, 拧开
            i = maxC # 更新最左节点
        return ans
```
