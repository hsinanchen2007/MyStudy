二分查找

遍历矩阵中的每一行
对于第i行，初始left和right分别是数组的第一个和最后一个元素的下标，mid=（left+right）/2。

```
 public bool SearchMatrix(int[,] matrix, int target)
        {
            if (matrix.Length == 0) return false;
            int row = matrix.GetLength(0);
            int col = matrix.GetLength(1);
            for (int i = 0; i < row; i++)
            {
                int left = 0;
                int right = col - 1;
                while (left <= right)
                {
                    int mid = (left + right) / 2;
                    if (matrix[i, mid] == target) return true;
                    if (matrix[i, mid] < target) left = mid + 1;//说明target不在左边
                    else right = mid - 1;//说明target不在右边边
                }
            }
            return false;
        }
```