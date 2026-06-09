### 解题思路
C# 回溯法

### 代码

```csharp
public class Solution {
    public IList<IList<int>> Combine(int n, int k) {
        if(n<1 || k<1) return new List<IList<int>>();
        List<IList<int>> results = new List<IList<int>>();
        List<int> currentList = new List<int>();
        BuildNumberList(1, n, k, ref currentList, ref results);
        return results;
    }

    private static void BuildNumberList(int start, int end, int length, ref List<int> currentList, ref List<IList<int>> results)
    {
        if (currentList.Count == length)
        {
            results.Add(new List<int>(currentList));
            return;
        }

        for (int index = start; index <= end; index++)
        {
            currentList.Add(index);
            BuildNumberList(index + 1, end, length, ref currentList, ref results);
            currentList.RemoveAt(currentList.Count - 1);
        }
    }
}
```