举例：输入2,3  [[0,1][1,1]]
0 0 0
0 0 0
设x={0,0}为开始时两行的变化次数
y={0,0,0}为开始时三列的变化次数
通过两次变化，可得知
x={1,1} y={0,2,0}
1 3 1
1 3 1
矩阵中奇数个数与xy的关系为：
矩阵中奇数个数 = x中奇数的个数 * 列数 + y中奇数的个数*行数 - x中奇数的个数 * y中奇数的个数 * 2
以此得出结论，有以下代码

```
    public int OddCells(int n, int m, int[][] indices) {
        int oddNum = 0;
        List<int> x = new List<int>();
        List<int> y = new List<int>();
        for (int i = 0; i < n; i++)
        {
            x.Add(0);
        }
        for (int i = 0; i < m; i++)
        {
            y.Add(0);
        }
        for (int i = 0; i < indices.Count(); i++)
        {
            x[indices[i][0]]++;
            y[indices[i][1]]++;
        }
        int xOdd = 0;
        for (int i = 0; i < n; i++)
        {
            if (x[i] % 2 != 0)
            {
                xOdd++;
            }
        }
        int yOdd = 0;
        for (int i = 0; i < m; i++)
        {
            if (y[i] % 2 != 0)
            {
                yOdd++;
            }
        }
        oddNum = xOdd * m + yOdd * n - xOdd * yOdd * 2;
        return oddNum;
    }
```
