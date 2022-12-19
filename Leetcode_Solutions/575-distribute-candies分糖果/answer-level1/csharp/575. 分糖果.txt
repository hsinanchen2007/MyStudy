### 解题思路
优化的Hash方法；有可能提前返回结果而不用扫描整个数组；

### 代码

```csharp
public class Solution {
    public int DistributeCandies(int[] candies) {
        var set = new HashSet<int>();
        var target = candies.Length / 2;
        foreach (var candy in candies)
        {
            set.Add(candy);
            if (set.Count == target) return target;
        }
        return set.Count;
    }
}
```