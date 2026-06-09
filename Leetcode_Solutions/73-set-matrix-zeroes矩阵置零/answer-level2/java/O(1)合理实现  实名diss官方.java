### 解题思路
![WX20200324-221619@2x.png](https://pic.leetcode-cn.com/f58b37d24c1e6efed7e3b012c54fa9640573ba01769bcae55a5d5cc97ce87220-WX20200324-221619@2x.png)


官方对于减去一个最大数字的做法在实际生活中可能有用，但是在这里完全不合理，好了话不多说看思路
我们需要找到一个行以及一个列作为标记，那么该如何选择呢，其实很简单，从头开始遍历，选择 第一个  matrix[x][y]=0  的行和列作为标记值即可，原因是改点所在的行和列肯定全部为0  但是前期我们并不对其进行初始化。
之后假设 matrix[i][j]=0  的等价条件呢就是第i行和j列为0
第i行为0  可以通过设置 matrix[i][y]=0 后期遍历处理实现
第j列为0  可以通过设置 matrix[x][j]=0 后期遍历处理实现 

首先遍历第y列 如果遍历过程中发现值为0，将该行所有的值置为0，这里需要注意的是当到了第x行，数据暂时不处理，但置为0  则无法判断哪一列需要置0了

接下来遍历第x行 如果遍历过程中发现值为0，将该列所有的值置为0

最后将第X行置为0；

### 代码

```java
class Solution {
    public void setZeroes(int[][] matrix) {

        int m = matrix.length;
        if(m == 0){
            return;
        }
        int n = matrix[0].length;
        int x = -1;
        int y = -1;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == 0){
                    if(x == -1){
                        x = i;
                        y = j;
                    }else{
                        matrix[x][j]= 0 ;
                        matrix[i][y] = 0;
                    }
                }
            }
        }
        if(x ==-1){
            return;
        }
        for(int i = 0;i<m;i++){
            if(x == i || matrix[i][y] != 0){
                continue;
            }
            for(int j = 0;j<n;j++){
                matrix[i][j] =0;
            }
        }
        for(int j=0;j<n;j++){
            if(matrix[x][j] != 0){
                continue;
            }
            for(int i=0;i<m;i++){
                matrix[i][j] =0;
            }
        }
        for(int j =0;j<n;j++){
            matrix[x][j]=0;
        }

    }
}
```