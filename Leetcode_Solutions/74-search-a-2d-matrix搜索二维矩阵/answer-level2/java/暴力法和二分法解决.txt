暴力法O(n*m)遍历整个二维数组
```
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0) return false;
        for (int i = 0; i<matrix.length;i++)
        {
            for (int j = 0; j<matrix[0].length; j++)
            {
                if (matrix[i][j] == target)
                {
                    return true;
                }
            }
        }
        return false;
    }
```

但是用二分法可以达到O(Logn), 但是要额外的空间复杂度O(1), 解决方法链接
[力扣](https://leetcode.com/problems/search-a-2d-matrix/discuss/299309/JAVA%3A-Simple-and-Concise-O(log-N)-solution-with-detailed-explanation)

```
 public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0)
        {
            return false;
        }
        int L = 0,R = (matrix.length * matrix[0].length)-1;

        while (L <= R)
        {
            int mid = (L+R) >>> 1;
            int row = getRow(matrix,mid);
            int column = getColumn(matrix,mid);

            if (matrix[row][column] == target) return true;
            else if (matrix[row][column] > target) R = mid-1;
            else L = mid+1;
        }
        return false;
    }

    private static int getRow(int[][]matrix, int mid)
    {
        return mid / matrix[0].length;
    }

    private static int getColumn(int[][]matrix,int mid)
    {
        return  mid % matrix[0].length;
    }
```