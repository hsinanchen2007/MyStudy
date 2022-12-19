### 解题思路
用两个BitSet分别存储行和列中为0的数。
第一次遍历中记录BitSet
第二次遍历，只要那个数不是0，并且在BitSet的行或者列中存在那就意味着这个数要被消掉，更改为0

### 代码

```java
class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        if(m<1) return ;
        int n = matrix[0].length;

        BitSet row = new BitSet();
        BitSet col = new BitSet();
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(matrix[i][j] ==0)
                {
                    row.set(i);
                    col.set(j);
                }
            }
        }

        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(matrix[i][j] !=0)
                {
                    if(row.get(i) || col.get(j))
                    {
                        matrix[i][j] =0;
                    }
                }
            }
        }
    }
}
```