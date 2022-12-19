### 解题思路
C# 数组排序 双指针递进比较

### 代码

```csharp
public class Solution {
    public int SmallestDifference(int[] a, int[] b) {
        Array.Sort(a);
        Array.Sort(b);
        int i, j;
        long closest = long.MaxValue;
        for (i = j = 0; i < a.Length && j < b.Length;)
        {
            closest = Math.Min(closest, Math.Abs((long)a[i] - (long)b[j]));
            if (a[i] < b[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return (int)closest;
    }
}
```