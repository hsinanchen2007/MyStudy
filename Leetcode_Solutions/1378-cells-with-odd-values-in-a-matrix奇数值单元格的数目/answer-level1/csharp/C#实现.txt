### 解题思路
实例化一个动态长度的二维数组（默认里边都是0的）
然后循环指定行列增加值，最后再循环遍历数组，是奇数就+1
### 代码

```csharp
public class Solution {
    public int OddCells(int n, int m, int[][] indices) {
        int[,] Arr = new int[n, m];
        int r = 0;
        foreach (var item in indices)
        {
            for (int i = 0; i < m; i++)
            {
                Arr[item[0], i]++;//行
            };
            for (int i = 0; i < n; i++)
            {
                Arr[i, item[1]]++;//列
            };
            //item[1]//列
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (Arr[i, j] % 2 == 1) r++;
            }
        }
        return r;
    }
}
```