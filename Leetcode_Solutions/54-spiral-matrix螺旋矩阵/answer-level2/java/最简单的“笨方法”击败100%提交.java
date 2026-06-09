### 解题思路
找规律往往会是解决这类问题的最高效方法。
规律就是以下步骤：
从m[0,0]开始，m*n矩阵
1.向右遍历到右边界n-1，
2.向下遍历到下边界m-1，
3.向左遍历到初始列0，
4.向上遍历到初始行0。
5.下一趟四步骤的初始行列均为0+1=1，右边界为n-1-1=n-2,下边界为m-1-1=m-2;
这个规律的代码实现不难，我们需要做的就是增加判断条件。具体参考以下代码：

### 代码

```java
class Solution {
    private int[][] matrix;
    private List<Integer> anslist=new ArrayList<>();
    
    private void oneCircle(int frow,int fcol,int brow,int bcol)
    {
        if(frow>brow)return;//如果首行就超出了边界行，说明之前所有行一定都遍历过了。那么必定不用再遍历了
        
        if(fcol>bcol)return;//如果首列就超出了边界列，也不用再遍历了。
        for(int i=fcol;i<=bcol;i++)//第一趟向右遍历        
            anslist.add(matrix[frow][i]);
        
        if(frow+1>brow)return;//说明所有行已经遍历完毕。完成。
        for(int i=frow+1;i<=brow;i++)//第二趟向下遍历
            anslist.add(matrix[i][bcol]);
        
        if(bcol-1<fcol)return;//说明所有列已经遍历完毕。完成
        for(int i=bcol-1;i>=fcol;i--)//第三趟向左遍历
            anslist.add(matrix[brow][i]);
        
        for(int i=brow-1;i>frow;i--)//第四趟向上遍历
            anslist.add(matrix[i][fcol]);

        oneCircle(frow+1,fcol+1,brow-1,bcol-1);//修改初始行列以及边界行列
    }
    public List<Integer> spiralOrder(int[][] matrix) {
        if(matrix.length==0)return anslist;
        this.matrix=matrix;
        int cols=matrix[0].length,rows=matrix.length;
        
        oneCircle(0,0,rows-1,cols-1);
        return anslist;
    }
}
```