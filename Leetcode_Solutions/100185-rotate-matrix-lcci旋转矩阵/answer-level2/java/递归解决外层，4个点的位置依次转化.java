### 解题思路
此处撰写解题思路
最外围  i 为第几行 j为矩阵中第第几个位置 j会随着递归第层数变化。

(i,j)->(i,n)->(n,n-j)->(n-j,0)->(i,j);

(0,0)->(0,3)->(3,3)->(3,0)->(0,0);
(0,1)->(1,3)->(3,2)->(2,0)->(0,1);
通过观察可以得到上方的变化，一个点绕着转化4次。

因为递归所以会有变化

然后递归下一层，因为deep=1；
此时（1，1）对应的实际上是新矩阵的(0,0);
因为i相对的没有变化所以可以不用处理
但是j有n-j这个存在就需要进行处理 j=n-i+deep; 加上一开始的偏移量
### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        dg(n, matrix, 0);
    }
    //先旋转最外层
    static void dg(int n, int[][] matrix, int deep){
        //这个小矩阵的长度
        int limit = n-1-deep;
        //只剩下一个的时候就不需要旋转了
        if(limit-deep<1){
            return;
        }
        for(int i=deep; i<limit;i++){
            int temp1 = matrix[i][limit];
            matrix[i][limit] = matrix[deep][i];

            int temp2 = matrix[limit][limit-i+deep];
            matrix[limit][limit-i+deep] = temp1;

            temp1 = matrix[limit-i+deep][deep];
            matrix[limit-i+deep][deep]=temp2;

            matrix[deep][i]=temp1;
        }
        //旋转接下来的一层
        dg(n,matrix,deep+1);
    }
}
```