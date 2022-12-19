### 解题思路
通过系统函数完成

### 代码

```csharp
public class Solution {
    public int NumberOfDays(int Y, int M) {
                DateTime _time = new DateTime(Y, M, 1);
                DateTime _time_end = _time.AddMonths(1);
                int day = (int)(_time_end - _time).TotalDays;
                return day;
    }
}
```