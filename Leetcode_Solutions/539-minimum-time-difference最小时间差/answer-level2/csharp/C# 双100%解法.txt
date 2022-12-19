### 解题思路
见注释。

### 代码

```csharp
public class Solution {
    static int ToMinutes(ReadOnlySpan<char> time) {
        return ((time[0] - '0') * 10 + (time[1] - '0')) * 60 + ((time[3] - '0') * 10 + (time[4] - '0'));
    }

    public int FindMinDifference(IList<string> timePoints) {
        if (timePoints.Count > 1440) return 0; // 根据鸽笼原理，时间数量超过1440肯定有2个是相等的，返回0即可

        Span<byte> bitmap = stackalloc byte[1440]; // 建立bitmap，时间对应下标的元素为1，否则为0
        var times = new int[timePoints.Count];
        for (int i = 0; i < times.Length; i++) {
            times[i] = ToMinutes(timePoints[i]); // 时间转分钟数
            ref byte bit = ref bitmap[times[i]];
            if (bit == 1) return 0; // 有2个是相等的，直接返回0
            bit = 1;
        }
        if (times.Length > 720) return 1; // 如果数量大于720，必定有2个时间间隔等于1

        int result = 1440;
        if (times.Length < 256) { // 数量太少了可以直接排序，然后取相邻元素差的最小值
            Array.Sort(times);
            for (int i = 1; i < times.Length; i++) {
                result = Math.Min(result, times[i] - times[i - 1]);
            }
            return Math.Min(result, times[0] + 1440 - times[times.Length - 1]);
        }

        // 下面根据bitmap取得最小相邻时间差
        int p1 = 0;
        while (bitmap[p1] == 0) p1++;
        int p = p1;
        for (int i = p + 1; i < bitmap.Length; i++) {
            if (bitmap[i] != 0) {
                if (i == p + 1) return 1;
                result = Math.Min(result, i - p);
                p = i;
            }
        }
        return Math.Min(result, p + 1440 - p1);
    }
}
```