很好理解的一种解决方法，代码如下所示：

```
public class Solution
{
    public IList<IList<int>> Generate(int numRows)
    {
        var list = new List<IList<int>>();
        for (int i = 0; i < numRows; i++)
        {
            var layer = Enumerable.Repeat(1, i + 1).ToList();
            if (i > 0)
            {
                var sub = list[i - 1];
                for (int j = 1; j < sub.Count; j++)
                {
                    layer[j] = sub[j - 1] + sub[j];
                }
            }
            list.Add(layer);
        }
        return list;
    }
}
```
