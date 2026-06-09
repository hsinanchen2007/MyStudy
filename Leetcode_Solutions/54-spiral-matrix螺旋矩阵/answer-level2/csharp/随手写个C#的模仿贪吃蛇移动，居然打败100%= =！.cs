public class Solution {
    int[][] _matrix;
    int[,] _count;
    int x = 0, y = 0, z = 1;
    public IList<int> SpiralOrder(int[][] matrix)
    {
        x = 0; y = 0; z = 1;
        _matrix = matrix;
        if (matrix.Length == 0 || matrix[0].Length == 0)
            return new List<int>();
        List<int> result = new List<int>();
        int m, n;
        m = matrix.Length;
        n = matrix[0].Length;
        _count = new int[m, n];

        try
        {
            while (_count[x, y] != 1)
            {
                if (z % 4 == 1)
                {
                    MoveRight(ref result, x, y, n);
                }
                else if (z % 4 == 2)
                {
                    MoveDown(ref result, x, y, m - 1);
                }
                else if (z % 4 == 3)
                {
                    MoveLeft(ref result, x, y, n - 1);
                }
                else
                {
                    MoveUp(ref result, x, y, m);
                }
                z++;
            }
        }
        catch { }
        return result;
    }
    public void MoveRight(ref List<int> result,int row,int col,int range)
    {
        for (int i = col; i < range + col; i++)
        {
            if (_count[row, i] != 1)
            {
                result.Add(_matrix[row][i]);
                _count[row, i] = 1;
                if (i == range + col-1)
                {
                    x = row + 1;
                    y = i;
                }
            }
            else
            {
                x = row + 1;
                y = i - 1;
                break;
            }
        }
    }
    public void MoveDown(ref List<int> result, int row, int col, int range)
    {
        for (int i = row; i < range + row; i++)
        {
            if (_count[i, col] != 1)
            {
                result.Add(_matrix[i][col]);
                _count[i, col] = 1;
                if (i == range + row - 1)
                {
                    x = i;
                    y = col - 1;
                }
            }
            else
            {
                x = i - 1;
                y = col - 1;
                break;
            }
        }
    }
    public void MoveLeft(ref List<int> result, int row, int col, int range)
    {
        for (int i = col; i > col - range; i--)
        {
            if (_count[row, i] != 1)
            {
                result.Add(_matrix[row][i]);
                _count[row, i] = 1;
                if (i == col - range + 1)
                {
                    x = row-1;
                    y = i ;
                }
            }
            else
            {
                x = row - 1;
                y = i + 1;
                break;
            }
        }
    }
    public void MoveUp(ref List<int> result, int row, int col, int range)
    {
        for (int i = row; i > row - range; i--)
        {
            if (_count[i, col] != 1)
            {
                result.Add(_matrix[i][col]);
                _count[i, col] = 1;
            }
            else
            {
                x = i + 1;
                y = col + 1;
                break;
            }
        }
    }
}