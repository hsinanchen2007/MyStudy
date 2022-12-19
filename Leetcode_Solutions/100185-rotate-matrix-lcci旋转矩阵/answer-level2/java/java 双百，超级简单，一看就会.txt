### 解题思路
这种题就是找规律，具体怎么找规律，请听我慢慢道来：
如题上3*3的矩阵所示：
需要说明的是，我这里的行是从0开始的！
（1）第0行->第2列；第1行->第1列；第2行->第0列；于是就有第i行->第N-i-1列
（2）第0列->第0行；第1列->第1行；第2列->第2行；于是就有第j列->第j行
于是matrix[i][j]->arr[j][N-i-1]
 

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int length=matrix.length;
        int[][] arr=new int[length][length];
        for(int i=0;i<length;i++)
        {
            for(int j=0;j<length;j++)
            {
                arr[j][length-i-1]=matrix[i][j];
            }
        }
        for(int i=0;i<length;i++)
        {
            for(int j=0;j<length;j++)
            {
                matrix[i][j]=arr[i][j];
            }
        }
    }
}
```