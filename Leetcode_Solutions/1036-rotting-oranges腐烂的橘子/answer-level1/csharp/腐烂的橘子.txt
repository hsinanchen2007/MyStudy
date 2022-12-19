### 解题思路
先打卡，有时间再整理一下思路

### 代码

```csharp
public class Solution {
    public int OrangesRotting(int[][] grid) {
        var goodOranges = new List<ValueTuple<int, int>>();
        var badOranges = new List<ValueTuple<int, int>>();
        for (int i = 0; i < grid.Length; i++)
        {
            for (int j = 0; j < grid[i].Length; j++)
            {
                if (grid[i][j] == 1)
                {
                    int a, b, c, d;
                    a = (i - 1) > -1 ? grid[i - 1][j] : 0;
                    b = (i + 1) < grid.Length ? grid[i + 1][j] : 0;
                    c = (j - 1) > -1 ? grid[i][j - 1] : 0;
                    d = (j + 1) < grid[i].Length ? grid[i][j + 1] : 0;
                    if (a + b + c + d == 0) return -1;  //如果好橘子周围都是空格，肯定不会感染，返回-1

                    goodOranges.Add(ValueTuple.Create(i, j));
                }
                else if (grid[i][j] == 2)
                {
                    badOranges.Add(ValueTuple.Create(i, j));
                }
            }
        }
        if (badOranges.Count == 0 && goodOranges.Count>0) return -1;
        int time = 0;
        while (goodOranges.Count != 0&& badOranges.Count!=0)
        {
            var newBadOranges = new List<ValueTuple<int, int>>();

            var result = false;
            foreach (var orange in badOranges)
            {
                result = goodOranges.Remove(ValueTuple.Create(orange.Item1 - 1, orange.Item2));
                if (result) newBadOranges.Add(ValueTuple.Create(orange.Item1 - 1, orange.Item2));

                result = goodOranges.Remove(ValueTuple.Create(orange.Item1 + 1, orange.Item2));
                if (result) newBadOranges.Add(ValueTuple.Create(orange.Item1 + 1, orange.Item2));

                result = goodOranges.Remove(ValueTuple.Create(orange.Item1, orange.Item2 - 1));
                if (result) newBadOranges.Add(ValueTuple.Create(orange.Item1 , orange.Item2-1));

                result = goodOranges.Remove(ValueTuple.Create(orange.Item1, orange.Item2 + 1));
                if (result) newBadOranges.Add(ValueTuple.Create(orange.Item1, orange.Item2+1));
            }
            time++;
            badOranges = newBadOranges;
        }
        if(goodOranges.Count>0) return -1;
        return time;
    }
}
```