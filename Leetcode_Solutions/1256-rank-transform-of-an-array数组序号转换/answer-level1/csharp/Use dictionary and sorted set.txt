### 解题思路
I tried to use the normal approach:
1. get distinct elements
2. sort and reverse the list/array
and the execution failed due to timeout.

To cope with the time requirements, I have to use dictionary and SortedSet to minimize the time, and it works.

### 代码

```csharp
public class Solution {
    public int[] ArrayRankTransform(int[] arr) {
        if (arr.Length == 0) { return arr; }

        Dictionary<string, int> sortedDistinctArr = new SortedSet<int>(arr).Select((input, index) => new {index, input}).ToDictionary(v => v.input.ToString(), v => v.index);

        return arr.Select(arrElem => sortedDistinctArr[arrElem.ToString()] + 1).ToArray();
    }
}
```