

```csharp
    public int[] FindDiagonalOrder(int[][] matrix)
    {
        
        if (matrix.Length == 0 || matrix[0].Length == 0)
        {
            return new int[0];
        }
        
        int rows = matrix.Length;
        int cols = matrix[0].Length;

        int[] res = new int[rows * cols];

        // 横坐标 + 纵坐标 = 定和，在同一对角线上
        Dictionary<int, List<int>> dic = new Dictionary<int, List<int>>();

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (!dic.ContainsKey(r + c))
                {
                    dic[r + c] = new List<int>();
                }

                dic[r + c].Add(matrix[r][c]);
            }
        }

        int index = 0;
        for (int i = 0; i < dic.Count; i++)
        {
            // 奇数是正序输出
            if (i % 2 != 0)
            {
                foreach (var temp in dic[i])
                {
                    res[index] = temp;
                    index++;
                }
            }
            else
            {
                foreach (var temp in dic[i].ToArray().Reverse())
                {
                    res[index] = temp;
                    index++;
                }
            }
        }

        return res;
    }
```
