### 解题思路
回溯法

### 代码

```csharp
public class Solution {
    public IList<IList<string>> SolveNQueens(int n)
    {
        var result = new List<IList<string>>();
        var map = Enumerable.Range(0, n).Select(index => new bool[n]).ToArray();
        ScanMap(map, 0, result);
        return result;
    }

    public void ScanMap(bool[][] map, int row, List<IList<string>> result)
    {
        if (map.Length == row)
        {
            result.Add(map.Select(array => string.Join(string.Empty,
                array.Select(value => value ? "Q" : "."))).ToList());
            return;
        }

        for (int index = 0; index < map[row].Length; index++)
        {
            if (!CheckPosition(map, index, row)) continue;

            map[row][index] = true;
            ScanMap(map, row + 1, result);
            map[row][index] = false;
        }
    }

    public bool CheckPosition(bool[][] map, int column, int row)
    {
        // 检查整列
        for (int index = 0; index < map.Length; index++)
        {
            if (map[index][column]) return false;
        }

        // 检查左上角
        for (int x = column - 1, y = row - 1; x >= 0 && y >= 0; x--, y--)
        {
            if (map[y][x]) return false;
        }

        // 检查右上角
        for (int x = column + 1, y = row - 1; x < map.Length && y >= 0; x++, y--)
        {
            if (map[y][x]) return false;
        }

        return true;
    }
}
```