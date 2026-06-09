### 解题思路
C# 转义为分钟数后排序 首尾邻接比较

### 代码

```csharp
public class Solution {
    public int FindMinDifference(IList<string> timePoints) {
        var minutes = timePoints.Select(time =>
        {
            var parts = time.Split(":");
            return int.Parse(parts[0]) * 60 + int.Parse(parts[1]);
        }).ToArray();
        Array.Sort(minutes);
        const int MaxDiff = 24 * 60;
        int minDiff = MaxDiff, currentDiff = 0;
        for (int index = 1; index < minutes.Length; index++)
        {
            currentDiff = Math.Min(
                minutes[index] - minutes[index - 1],
                minutes[index - 1] + MaxDiff - minutes[index]);
            minDiff = Math.Min(minDiff, currentDiff);
        }

        // 处理首尾
        currentDiff = minutes[0] + MaxDiff - minutes[minutes.Length - 1];
        minDiff = Math.Min(minDiff, currentDiff);

        return minDiff;
    }
}
```