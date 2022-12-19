**方法一：分类讨论**

对于列表 `intervals` 中的每个区间，我们可以依次判断出它们和待删除区间 `toBeRemoved` 的交集，并将剩余的部分添加进答案中。设 `intervals` 中的某个区间为 `[x, y)`，待删除区间为 `[toL, toR)`，那么会有以下三种情况：

1. `[x, y)` 被全部保留，此时 `[x, y)` 和 `[toL, toR)` 不相交，需要满足 `toL >= y`（待删除区间在右侧）或 `toR <= x`（待删除区间在左侧）；

2. `[x, y)` 的前缀区间（但不是整个区间）`[x, toL)` 被保留，需要满足 `x < toL < y`；

3. `[x, y)` 的后缀区间（但不是整个区间）`[toR, y)` 被保留，需要满足 `x < toR < y`；

注意到情况一和其它情况都是互斥的，并且情况二和情况三可能会同时发生。例如当 `[x, y) = [1, 10)`，`[toL, toR) = [3, 5)` 时，前缀区间 `[1, 3)` 和后缀区间 `[5, 10)` 均被保留。并且当情况一没有发生时，根据摩根律（取反律）一定有 `toL < y` 且 `toR > x`，因此在判断情况二和情况三时，我们只需要额外判断 `toL > x` 或 `toR < y` 即可。

综上所述，我们可以根据以下的逻辑判断每个区间 `[x, y)` 的保留情况：

- 若 `[x, y)` 和 `[toL, toR)` 不相交，那么 `[x, y)` 被全部保留；

- 否则 `[x, y)` 和 `[toL, toR)` 相交，那么 `[x, y)` 的前缀区间和后缀区间都可能被保留。

  - 若 `toL > x`，那么前缀区间 `[x, toL)` 被保留；

  - 若 `toR < y`，那么后缀区间 `[toR, y)` 被保留。

```C++ [sol1]
class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int toL = toBeRemoved[0], toR = toBeRemoved[1];
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); ++i) {
            int x = intervals[i][0], y = intervals[i][1];
            if (toL >= y || toR <= x) {
                ans.push_back({x, y});
            }
            else {
                if (toL > x) {
                    ans.push_back({x, toL});
                }
                if (toR < y) {
                    ans.push_back({toR, y});
                }
            }
        }
        return ans;
    }
};
```

```Python [sol1]
class Solution:
    def removeInterval(self, intervals: List[List[int]], toBeRemoved: List[int]) -> List[List[int]]:
        toL, toR = toBeRemoved
        ans = list()
        for x, y in intervals:
            if toL >= y or toR <= x:
                ans.append([x, y])
            else:
                if toL > x:
                    ans.append([x, toL])
                if toR < y:
                    ans.append([toR, y])
        return ans
```

**复杂度分析**

- 时间复杂度：$O(N)$，其中 $N$ 是数组 `intervals` 的长度。

- 空间复杂度：$O(1)$。