### 解题思路
这个题很有意思。

题目中的要求是沿对角线蛇形遍历一个矩阵，我们先来分析这种遍历在坐标上的规律：

1. 对于矩形来说，矩形对角线是最长的，也是遍历结果最长的一条，从这条线，到两边对称递减

2. 遍历顺序：从左下角到右上角交错进行

根据以上两个特点，我们可以想到是否同一条线上的坐标有数上的关系，而且，交替遍历是否可以看成奇数和偶数的替换呢？带着这种思考我们解析这个矩阵(以图中矩阵为例子)：

![截屏2020-03-26下午11.49.03.png](https://pic.leetcode-cn.com/4046c9a78c9872b656b7fe6fa6ee244200a27384d4604e46e5538ecc5df40496-%E6%88%AA%E5%B1%8F2020-03-26%E4%B8%8B%E5%8D%8811.49.03.png)

1. 我们现在将每一条对角线作出从0 开始的编号，可以发现最后一个的编号是 `M + N - 1`；并且如果编号为奇数自上而下遍历，偶数则是自下而上遍历

2. 关注每一条对角线上的坐标和：对于每一条对角线上的坐标`(m,n)`，`m + n = 编号` 是我们发现的规律

3. 最后一步就是确定边界：
    1. 多少次遍历：矩阵有多少个元素就遍历多少次
    2. 到什么时候结束：对于最长对角线以上来说，到 m 或者 n 中的某一个到 0 为止；对于最长对角线下面来说，到 m 或者 n 中的某一个到达边界为止。

下面是代码部分：
### 代码

```java
class Solution {
    public int[] findDiagonalOrder(int[][] matrix) {
        if(matrix.length == 0)
            return new int[0];
        int size = matrix.length * matrix[0].length;
        int index = 0;
        int[] result = new int[size];
        int maxK = matrix.length + matrix[0].length;
        
        for(int k = 0; k < maxK; k++)
        {
            int m = 0, n = 0;
            
            if(k % 2 == 0) //偶数部分
            {
                if(k < matrix.length)
                {
                    m = k;
                    n = 0;
                }
                else
                {
                    m = matrix.length - 1;
                    n = k - m;
                }
                while(m >= 0 && n < matrix[0].length) //n到达边界为止
                {
                    result[index++] = matrix[m][n];
                    m--;
                    n++;
                }
            }
            else //奇数部分
            {
                if(k < matrix[0].length)
                {
                    m = 0;
                    n = k;
                }
                else
                {
                    n = matrix[0].length - 1;
                    m = k - n;
                }
                while(m < matrix.length && n >= 0) //m到达边界为止
                {
                    result[index++] = matrix[m][n];
                    m++;
                    n--;
                }
            }
        }
        
        return result;
    }
}
```