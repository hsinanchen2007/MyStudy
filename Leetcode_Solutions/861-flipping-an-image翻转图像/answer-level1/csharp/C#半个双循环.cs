遍历数组，将每一行的头和尾互换并改值，这个不难理解。需要说的是，经过试验，两两互换最优的应该是b-a，b-a，b+a的方式，比异或快，更比中间值快而且省空间
```
    public int[][] FlipAndInvertImage(int[][] A) {
        int n = A.Count();
        for (int i = 0; i < n; i++)
        {
            if (n % 2 == 0)
            {
                for (int j = 0; j < n / 2; j++)
                {
                    A[i][j] = A[i][n - j - 1] - A[i][j];
                    A[i][n - j - 1] = A[i][n - j - 1] - A[i][j];
                    A[i][j] = A[i][n - j - 1] + A[i][j];
                    A[i][j] = (A[i][j] + 1) % 2;
                    A[i][n - j - 1] = (A[i][n - j - 1] + 1) % 2;
                }
            }
            else
            {
                for (int j = 0; j <= n / 2; j++)
                {
                    if (j != n / 2)
                    {
                        A[i][j] = A[i][n - j - 1] - A[i][j];
                        A[i][n - j - 1] = A[i][n - j - 1] - A[i][j];
                        A[i][j] = A[i][n - j - 1] + A[i][j];
                        A[i][j] = (A[i][j] + 1) % 2;
                        A[i][n - j - 1] = (A[i][n - j - 1] + 1) % 2;
                    }
                    else
                    {
                        A[i][j] = (A[i][j] + 1) % 2;
                    }
                }
            }
        }
        return A;
    }
```
