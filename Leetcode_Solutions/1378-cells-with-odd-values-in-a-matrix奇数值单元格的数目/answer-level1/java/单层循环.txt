### 解题思路
借鉴某位老哥的思路，豁然开朗。

### 代码

```java
class Solution {
    public int oddCells(int n, int m, int[][] indices) {
        boolean[] row=new boolean[n];
        boolean[] col=new boolean[m];
        for(int i=0;i<indices.length;i++)
        {
            row[indices[i][0]]=!row[indices[i][0]];
            col[indices[i][1]]=!col[indices[i][1]];
        }
        //奇数次处理行数和列数
        int ans_r=0,ans_c=0;
        for(int i=0;i<row.length;i++)
        {
            if(row[i])
            {
                ans_r++;
            }
        }
         for(int i=0;i<col.length;i++)
        {
            if(col[i])
            {
                ans_c++;
            }
        }
        //集合角度来看
        return ans_r*m+ans_c*n-2*ans_r*ans_c;
    }
}
```