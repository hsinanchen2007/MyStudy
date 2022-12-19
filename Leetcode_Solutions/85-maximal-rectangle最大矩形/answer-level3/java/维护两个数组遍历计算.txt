### 解题思路
6*5 matrix:
            {'0','1','1','0','1'},
            {'1','1','0','1','0'},
            {'0','1','1','1','0'},
            {'1','1','1','1','0'},
            {'1','1','1','1','1'},
            {'0','0','0','0','0'}
现在，维护两个一维数组`rlen[]`,`clen`;
1. `rlen[i]`:i行上目前为止延续最多1的长度。例如到了`matrix[0][2]`时，`rlen[0]=2`,而到了`matrix[0][4]`时，`rlen[0]=1`
2. `clen[j]`:j列上目前为止延续最多1的长度。例如到了`matrix[1][0]`时,`clen[0]=1`，而到了`matrix[4][0]`时，`clen[0]=2`
3. 有了`rlen`和`clen`的概念后，我们就可以遍历matrix，边遍历边记录`rlen`与`clen`， 每次计算最大值的面积的方法是：
    -从当前列`j`开始，向左遍历`rlen[i]`个列，每次得出最小的高度`min=Math.min(min,clen[j])`
    -算出当前的最大值`max=Math.max(min*len,max)`，其中`len`表示已经遍历的列数。
于是，具体的代码思路如下：
遍历matrix:
1.如果`matrix[i][j]==1`:
    -如果matrix[i][j-1]==1:clen[j]++;否则clen[j]=1;
    -如果matrix[i-1][j]==1:rlen[i]++;否则rlen[i]=1;
    -按照上诉第3点思路计算最大的面积。
2.如果`matrix[i][j]==0`，继续。
### 代码

```java
class Solution {
    private int max=0;
    public int maximalRectangle(char[][] matrix) {
        
        if(matrix.length==0||matrix[0].length==0)return 0;
        
        int r=matrix.length,c=matrix[0].length;
        int clen[]=new int[c];
        int rlen[]=new int[r];
        
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(matrix[i][j]=='1')
                {
                    if(j>0&&matrix[i][j-1]=='1')rlen[i]++;
                    else rlen[i]=1;
                    if(i>0&&matrix[i-1][j]=='1')clen[j]++;
                    else clen[j]=1;
                    
                    colsJudge(clen,j+1-rlen[i],j);
                }
        return max;
    }
    private void colsJudge(int[] clen,int begin,int end)
    {
        int min=clen[end];
        for(int i=end;i>=begin;i--)
        {
            min=Math.min(clen[i],min);
            max=Math.max(min*(end-i+1),max);
        }
    }
}
```

### 时间复杂度
不难看出，时间复杂度达到o(n*m^2),原本以为会很慢，没想到还是可以击败65%的提交，本次题解也只是我的一个思路而已，我还是再去看一下效率更高的优秀题解吧。
后来看了一下官方题解，发现第二种解思路基本跟我的一样，不过比我更简单易懂一点，如果各位有看不懂的可以去看一下官方的题解，写的还是很不错的。