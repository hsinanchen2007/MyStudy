### 解题思路
将图片拆分为9个部分,中间部分是需要作9个数的均算的
中间的上下左右分别要作6个数的均算
四个角分别要作4个数的均算
1.利用两个和矩阵列长度的数组记录图片的第一行求和数据与第二行求和数据
由于当前行总是要读取下一行的数据,故而可以将当前行数据覆盖掉
2.写完数据将记录数据的两行下移
3.最后一行直接使用记录数据的数组运算即可
注意 : 当存在单行或单列需要单独计算
对于长条型或者竖条型的图片,该算法可以优化,但是如何作到代码复用?
i,j是个问题..........

### 代码

```java
class Solution {
    public int[][] imageSmoother(int[][] M) {
        
        if(M.length <= 1 && M[0].length <= 1) return M;
        if(M.length <= 1) return singletonRow(M);
        if(M[0].length <= 1)return singletonColunm(M);
        //使用行列计算
        int[] one = new int[M[0].length];
        int[] two = new int[M[0].length];
        int tail = M[0].length - 1;
        int height = M.length - 1;//这里代表的是高度-1
        //记录第一行的值,头和尾只加两个
        one[0] = M[0][0] + M[0][1];
        for(int i=1;i<tail;i++){
            one[i] = M[0][i-1] + M[0][i] + M[0][i+1];
        }
        one[tail] = M[0][tail-1] + M[0][tail];
        //记录第二行的值,并计算M的第一行
        two[0] = M[1][0] + M[1][1];
        M[0][0] = (one[0] + two[0]) / 4;
        for(int i=1;i<tail;i++){
            two[i] = M[1][i-1] + M[1][i] + M[1][i+1];
            M[0][i] = (one[i] + two[i]) / 6;
        }
        two[tail] = M[1][tail-1] + M[1][tail];
        M[0][tail] = (one[tail] + two[tail]) / 4;

        //计算M的第2行到 M.length-2行
        for(int i=1;i < height;i++){
            int temp = 0 ;
            //中间的部分
            for(int j=1;j<tail;j++){
                temp = M[i+1][j-1] + M[i+1][j] + M[i+1][j+1];
                M[i][j] = (one[j] + two[j] + temp) / 9;
                one[j] = two[j];
                two[j] = temp;
            }
            //依然是计算每一行的第一个与最后一个
            temp = M[i+1][0] + M[i+1][1];
            M[i][0] = (one[0] + two[0] + temp) / 6;
            one[0] = two[0];
            two[0] = temp;

            temp = M[i+1][tail-1] + M[i+1][tail];
            M[i][tail] = (one[tail] + two[tail] + temp) / 6;
            one[tail] = two[tail];
            two[tail] = temp;
        }

        //计算最后一行进行收尾
        M[height][0] = (one[0] + two[0]) / 4;
        M[height][tail] = (one[tail] + two[tail]) / 4;
        for(int i =1;i < tail;i++)
            M[height][i] = (one[i] + two[i]) / 6;

        return M;
    }

    public int[][] singletonRow(int[][] M){
        int pre = M[0][0];
        M[0][0] = (M[0][0] + M[0][1]) / 2;
        for(int i = 1;i<M[0].length - 1;i++){
            int temp = M[0][i];
            M[0][i] = (pre + temp + M[0][i+1]) / 3;
            pre = temp;
        }
        M[0][M[0].length - 1] = (pre + M[0][M[0].length - 1]) / 2;
        return M;
    }

    public int[][] singletonColunm(int[][] M){
        int pre = M[0][0];
        M[0][0] = (M[0][0] + M[1][0]) / 2;
        for(int i = 1;i<M.length - 1;i++){
            int temp = M[i][0];
            M[i][0] = (pre + temp + M[i+1][0]) / 3;
            pre = temp;
        }
        M[M.length - 1][0] = (pre + M[M.length - 1][0]) / 2;
        return M;
    }
}
```