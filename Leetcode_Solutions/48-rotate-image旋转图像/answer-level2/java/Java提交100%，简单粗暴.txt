![leetcode48.png](https://pic.leetcode-cn.com/4a961abec29c91fd50232aebabcbb340f97c3410e8901854ae05fa4ac5e5e4b8-leetcode48.png)

### 解题思路
其实这道题不难，关键在于翻转90度应该怎么原地去翻转
手动翻转个例子就不难发现以下事实，对于n×n矩阵m中:
1.m[i,j]元素的向右90度的下标为m[j,n-i-1];
2.一趟完整的翻转需要经历4次，一趟完整的翻转如下图所示：
![leetcode48solve.png](https://pic.leetcode-cn.com/ecd65b4a35374c0ce55018383daffbd1276debd9fad788baf4cc4e401280be40-leetcode48solve.png)
上图中一趟转换经历这4步：
原m[0,1]值->m[1,3];
原m[1,3]值->m[3,2];
原m[3,2]值->m[2,0];
原m[2,0]值->m[0,1];
知道这些，写出代码就不难了。
### 代码

```java
class Solution {
    public void rotate(int[][] matrix) 
    {
        int n=matrix[0].length;
        int pre=0;
        for(int i=0;i<n/2;i++)
        {
            for(int j=i;j<n-i-1;j++)
            {
                pre=matrix[i][j];
                int row=i,col=j;
                int count=0;
                while(count++<4)//四步骤
                {
                    //System.out.println("change:["+row+","+col+"]"+pre+"->["+col+","+(n-row-1)+"]"+matrix[col][n-row-1]+";");
                    int temp=matrix[col][n-row-1];
                    matrix[col][n-row-1]=pre;
                    pre=temp;
                    int temprow=row;
                    row=col;
                    col=n-temprow-1;
                }
            }
        }
    }
}
```