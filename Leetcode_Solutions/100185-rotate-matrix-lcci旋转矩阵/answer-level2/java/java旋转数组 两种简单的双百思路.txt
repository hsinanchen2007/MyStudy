## 思路 

旋转数组的思路有两种，一种是找到旋转后的位置，直接旋转，第二种是利用翻转。

### 直接旋转

首先看第一种：要找到旋转后的位置，关键是要找到旋转位置与原位置的关系。  
这里主要分为两种情况：

#### 情况1：矩阵的大小n为偶数

这里以4*4的矩阵为例，如下图所示：

![1.png](https://pic.leetcode-cn.com/aadbd677e68191adc68e3a59e9b5c70e686caa4f7f6c105916c8d07424cf36e5-1.png)

我们可以看到，其实只要对编号为1,2,3,4的这一个大块进行旋转就可以了，我们以编号1的小块为例。  
左上角的块1可以旋转到右上角的块1，而右上角的块1也可以直接旋转到右下角的块1，同理，右下角的旋转到左下角，左下角的旋转到左上角。当我们完成了这些步骤，那么左上、右上、左下、右下这四个部分的块1都已经完成了旋转。同样的，我们将1,2,3,4这个大块的其他小块按照同样的步骤完成旋转，那么整个矩阵就完成了旋转。 

#### 情况2：矩阵的大小n为奇数

5*5的矩阵为例，如下图所示：

![2.png](https://pic.leetcode-cn.com/edbdb19ccb8b8a4ab492609fc8c6c1a7374cf345ebfc2cea3b5cb6fd9dad2eb0-2.png)

对于奇数的情况，由图可知，其实只是增加了第三列的小块（3,6）。前面的四个小块(1,2,4,5)和情况1一样。而块7作为中心块，则不需要旋转。

#### Coding

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for(int i = 0; i < n/2; i++){
            //考虑到n为奇数时，需要遍历的行多加一行或者列多加一列
            //这里取列多一列，所以就为：n+1/2。
            for(int j = 0; j < (n+1)/2; j++){
                int tmp = matrix[i][j];
                //左下角旋转到左上角
                matrix[i][j] = matrix[n-1-j][i];
                //右下角旋转到右下角
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                //右上角旋转到右下角
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                //左上角旋转到右上角
                matrix[j][n-1-i] = tmp;
            }
        }
    }
}
```

### 翻转

其实要实现旋转，我们可以利用对角线和水平或者垂直进行翻转。

其中：先进行左上-右下的对角线翻转，然后再进行垂直翻转，可以得到顺时针旋转的矩阵，进行水平翻转可以得到逆时针，这点你自己动手画一个图，就会很清晰了。

```
1 2 3  对角线翻转   1 4 7  垂直翻转   7 4 1   
4 5 6  =========>  2 5 8  ========>  8 5 2
7 8 9  沿着1-5-9   3 6 9  沿着4-5-6   9 6 3
```

- 对角线的翻转就是矩阵的转置，即(i,j) -> (j,i) 下标交换就行。  
- 垂直翻转就是对称的列两两交换。

#### Coding

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        //对角线翻转
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        //垂直翻转
        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < n; j++){
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
        }
    }
}
```