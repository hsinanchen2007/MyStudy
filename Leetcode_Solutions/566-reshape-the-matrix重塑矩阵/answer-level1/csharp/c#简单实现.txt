### 解题思路
简单的实现思路

### 代码

```csharp
public class Solution {
    public int[][] MatrixReshape(int[][] nums, int r, int c) {
        int x=nums.Length;
        int y=nums[0].Length;

        if(r*c!=x*y)
        {
            return nums;
        }
        else
        {
            int tempA=0;
            int tempB=0;
            int[][] result=new int[r][];
            int[] row=new int[c];
            for(int i=0;i<x;i++)
            {
                for(int j=0;j<y;j++)
                {
                    row[tempB]=nums[i][j];
                    tempB++;

                    if(tempB==c)
                    {
                        result[tempA]=row;
                        row=new int[c];
                        tempB=0;
                        tempA++;
                    }
                }
            }
            return result;
        }
    }
}
```