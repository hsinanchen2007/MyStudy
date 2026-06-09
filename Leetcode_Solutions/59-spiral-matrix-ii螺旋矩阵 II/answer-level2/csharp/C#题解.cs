
主要思路是把矩阵想象成棋盘，从左上角出发后向右前进，每进入一格就填充数字，遇到边界就右转（下一步就会越界或下一步的格子已经被填充），代码如下

```
public class Solution {
    public int[][] GenerateMatrix(int n) {
        int[][] m = new int[n][];
        for(int i = 0; i < n; i++)
        {
            m[i] = new int[n];
        }
        int n2 = n * n;
        int x = 0, y = 0;
        Direction d = Direction.Right;
        for(int i = 1; i <= n2; i++)
        {
            m[x][y] = i;
            switch(d)
            {
                case Direction.Right:
                    y++;
                    if(y>=n-1 || m[x][y+1]!=0)
                        d = Direction.Dowm;
                    break;
                case Direction.Dowm:
                    x++;
                    if(x>=n-1 || m[x+1][y]!=0)
                        d = Direction.Left;
                    break;
                case Direction.Left:
                    y--;
                    if(y<=0 || m[x][y-1]!=0)
                        d = Direction.Up;
                    break;
                case Direction.Up:
                    x--;
                    if(x<=0 || m[x-1][y]!=0)
                        d = Direction.Right;
                    break;
            }
        }
        return m;
    }
}

public enum Direction
{
    Up,
    Dowm,
    Left,
    Right
}
```
