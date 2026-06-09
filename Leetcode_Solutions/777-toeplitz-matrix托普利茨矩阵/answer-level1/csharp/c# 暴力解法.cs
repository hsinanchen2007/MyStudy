### 解题思路
几个事项：
1.左下角和右上角的值不用判断，因为只有一个值。
2.所有对角线的开始在第一行或第一列内。

### 代码

```csharp
public class Solution {
    public bool IsToeplitzMatrix(int[][] matrix) {
        int x=matrix.Length;
        int y=matrix[0].Length;

        for(int i=y-2;i>-1;i--)
        {
            int current=matrix[0][i];
            int tempX=0;
            int tempY=i;

            while(tempX+1<x&&tempY+1<y)
            {
                tempX++;
                tempY++;
                if(current!=matrix[tempX][tempY])
                {
                    return false;
                }
            }
        }

        for(int i=1;i<x-1;i++)
        {
            int current=matrix[i][0];
            int tempX=i;
            int tempY=0;

            while(tempX+1<x&&tempY+1<y)
            {
                tempX++;
                tempY++;
                if(current!=matrix[tempX][tempY])
                {
                    return false;
                }
            }
        }

        return true;
    }
}
```