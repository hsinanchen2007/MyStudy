### 解题思路
只要找到旋转之后与旋转之前的坐标关系，然后，对每一个位置的数字替换即可
具体关系可以画出旋转后与转换前的图，来发现，例如4×4的矩阵：
![QQ图片20200407020618.png](https://pic.leetcode-cn.com/ed1d6fadf1352782bed01866edb5f4a217c08043d7fb3749b2e5a04740b93deb-QQ%E5%9B%BE%E7%89%8720200407020618.png)
这是一张旋转之后的图片，单元格里面放的是，旋转前，该数字所在的单元格的坐标
对其标上坐标轴：
![未标题-1.png](https://pic.leetcode-cn.com/50d4dc89b7ef633c8a7a93673fd0630832ff73900d7e4739bddfdf10a8966c5c-%E6%9C%AA%E6%A0%87%E9%A2%98-1.png)
蓝色为旋转前的坐标轴，红色为旋转后的坐标轴
对比可以发现，旋转前的X坐标变成了旋转之后的Y坐标，旋转前的Y坐标跟旋转后的X坐标的和为N-1
故旋转后的图，某个位置(x, y)的数，为旋转前(N-y-1, x)位置的数
即，变形公式为：matrix[i][j] = matrix[N-j-1][i]
#### 注意
与每个位置关联的位置有三个，即每次交换的位置有四个


### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    const int N = matrixColSize[0] - 1;
    int l = 0, r = N, t, i;
    while(l <= r) {
        for(i = l; i < r; ++i) {
            t = matrix[l][i];
            matrix[l][i] = matrix[N-i][l];
            matrix[N-i][l] = matrix[N-l][N-i];
            matrix[N-l][N-i] = matrix[i][N-l];
            matrix[i][N-l] = t;
        }
        ++l, --r;
    }
}
```