
**我们知道第一个点的坐标 是基于（0，0）给的， i 是到第一行的距离， j是到第一列的距离。**

圆圈 代表点，各个点基于一个正方形给的坐标，要将其全部转换为 第一个正方形的坐标(即为真正坐标)。
经过旋转后，如下图。

--- 
![QQ图片20200407105624.png](https://pic.leetcode-cn.com/4f0d1c9dce02eaab1507b349fa96946df804b21fb884a7bdf5ee9e80b7d31cde-QQ%E5%9B%BE%E7%89%8720200407105624.png)


第一个圆圈的坐标为正常的 ：(i，j)。
转换后二 ： (j,N-i-1)
转换后三 ： (N-i-1, N-j-1)
转换后四 ： (N-j-1,i)

故选择四分之个区域，将其四个坐标进行 循环更换即可。


```java
class Solution {
    public void rotate(int[][] matrix) {
        int N = matrix.length;
        // 选择 四分之一区域 
        for(int i = 0; i < N / 2; i++){
            for(int j = 0; j < (N + 1) / 2; j++){ // 四个坐标 轮流转换。
                int temp = matrix[i][j];
                matrix[i][j] = matrix[N - j - 1][i];
                matrix[N - j - 1][i] = matrix[N - i - 1][N - j - 1];
                matrix[N - i - 1][N- j - 1] = matrix[j][N - i - 1];
                matrix[j][N - i - 1] = temp;
            }
        }
    }
}
```

画图太烂，大家见谅。