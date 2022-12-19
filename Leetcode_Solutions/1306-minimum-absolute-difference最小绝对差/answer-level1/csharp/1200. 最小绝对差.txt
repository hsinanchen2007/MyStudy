### 解题思路
C# 数组排序 一次遍历

### 代码

```csharp
public class Solution {
    public IList<IList<int>> MinimumAbsDifference(int[] arr) {
        var results = new List<IList<int>>();
        int minDiff = int.MaxValue;
        Array.Sort(arr);
        for (int index = 1; index < arr.Length; index++)
        {
            int diff = arr[index] - arr[index - 1];
            if (diff < minDiff)
            {
                results.Clear();
                results.Add(new List<int>() { arr[index - 1], arr[index] });
                minDiff = diff;
            }
            else if (diff == minDiff)
            {
                results.Add(new List<int>() { arr[index - 1], arr[index] });
            }
        }
        return results;
    }
}
```