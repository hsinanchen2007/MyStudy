### 解题思路
此处撰写解题思路

首先设计一个将矩阵中某四个元素顺时针旋转90°的函数ring。

如果n=方形矩阵.length;
那么只需将第 i 行的第 j = i 到 j = ( n - 1 ) / 2 列元素进行ring就可以了


### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int i = 0, j = 0;
        
        while(i <= (n - 1) / 2){//控制两个指针，只需指定四分之一的矩阵元素即可，因为每次旋转都旋转4个元素
            if (j <= n - 2 - i) {
                ring(matrix, i, j);
                j++;
            } else {
                i++;
                j = i;
            } 
        }
    }

    public void ring(int[][] m, int i, int j) {//指定一个元素，将这个元素逆时针交换3次
        int ni = m.length, nj = m[0].length;
        assert ni == nj;
        
        int ti, tj;
        for (int k = 0; k < 3; k++) {//当前元素逆时针交换三次后逆时针转270°，即顺时针90°，同时路线上其他元素也顺时针转90°

            ti = m.length - 1 - j;//指定逆时针方向上对应矩阵索引ti
            tj = i;//指定逆时针方向上对应矩阵索引tj

            //进行交换
            int tmp = m[i][j];
            m[i][j] = m[ti][tj];
            m[ti][tj] = tmp;
            
            //指向目标索引
            i = ti;
            j = tj;
        }
    }
}
```