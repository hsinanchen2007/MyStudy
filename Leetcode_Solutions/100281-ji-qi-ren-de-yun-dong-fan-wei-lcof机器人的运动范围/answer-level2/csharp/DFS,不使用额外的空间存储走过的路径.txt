```
  public   int GetCount(int[][] a, int i, int j, int k)
        {
            if (i < 0 || j < 0 || i > a.Length - 1 || j > a[0].Length - 1 || a[i][j] == -1)
            {
                return 0;
            }
            a[i][j] = -1;
            int ii = i, jj = j;
            int sumi = 0, sumj = 0;
            while (ii != 0)
            {
                sumi = sumi  + ii % 10;
                ii = ii / 10;
            }
            while (jj != 0)
            {
                sumj = sumj  + jj % 10;
                jj = jj / 10;
            }
            if (sumi + sumj <= k)
            {
                return 1 + GetCount(a, i, j + 1, k) + GetCount(a, i + 1, j, k);
            }
            else
            {
                return 0;
            }
        }
        public   int MovingCount(int m, int n, int k)
        {
            if (k == 0)
            {
                return 1;
            }
            var a = new int[m][];
            for (int i = 0; i < m; i++)
            {
                a[i] = new int[n];
            }
            return GetCount(a, 0, 0, k);
        }
```
