拿题目 示例一 做样例
![WS84\[{W4@CN``E_9H\[VDXGW.png](https://pic.leetcode-cn.com/27f9c49228a06e6dfa713e4f2c9120ced40a092caa27b89c6edd503dd790b9df-WS84%5B%7BW4@CN%60%60E_9H%5BVDXGW.png)
然后我们按照对翻转后的矩阵进行标记，从上到下从左到右：
![2.png](https://pic.leetcode-cn.com/5425cacc6911533544abeda1905c9f01f510d42471a92b68add663ec27af27c8-2.png)
那么，我们就可以得出原来矩阵对应的标记位置：
![3.png](https://pic.leetcode-cn.com/36d6c306ec51f93daba77b9d66d343c5f6776d129be3bbf6e7cc379f8b7454ff-3.png)
从原矩阵中可以看出**标记的顺序是从第一列到最后一列，每列都是从下到上**
**我们只需要按照这个标记顺序，用一维数组把数据保存起来，再按顺序赋值给原数组就行了**
例如当前按照原矩阵标记顺序保存的数据为：7 4 1 8 5 2 9 6 3，
再赋值给原数组
7 4 1
8 5 2
9 6 3
这样就得到了答案
上代码
```java []
class Solution {
    public void rotate(int[][] matrix) { 
        int N = matrix.length;
        int[] b = new int[N * N];           // 保存旋转后的顺序情况
        int index = 0;
        for(int i = 0; i < N; i ++)         // i表示列，从0到N-1    
            for(int j = N - 1; j >= 0; j --)// j表示行，从N-1到0
                b[index ++] = matrix[j][i]; // 记录数据
        index = 0;
        for(int i = 0; i < N; i ++)         // 按顺序赋值即可
            for(int j = 0; j < N; j ++)
                matrix[i][j] = b[index ++];
    }
}
```
![4.png](https://pic.leetcode-cn.com/a293dfda231182c700d2a7ea09623095a2ccd6f64db123fc9557bc8f7a48fdd5-4.png)
***第一次在lc写题解，觉得写得不错就给个赞吧~~~***



