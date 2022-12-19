> 思路描述：旋转矩阵，首先先写一个占用额外内存空间的，这个完全不需要去讲思路的兄弟们，一脸懵的拿了100%。。。

```C++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> matrix2(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j ++){
                matrix2[j][n - i - 1] = matrix[i][j];
            }
        }
        matrix = matrix2;
    }
};
```

![image.png](https://pic.leetcode-cn.com/0fb7da37faaf7471d93c213ed2155bcf4976e5a6a87fd356aa0829a6f40b68ed-image.png)

> 当然我们去思考一下不占用额外内存空间的，下面是一个特别好的思路，但是一般人想不到就是了
>
> ```C++
> 我们还可以另辟蹊径，用翻转操作代替旋转操作。我们还是以题目中的示例二
> 
>  5  1  9 11
>  2  4  8 10
> 13  3  6  7
> 15 14 12 16
> 作为例子，先将其通过水平轴翻转得到：
> 
>  5  1  9 11                 15 14 12 16
>  2  4  8 10                 13  3  6  7
> ------------   =水平翻转=>   ------------
> 13  3  6  7                  2  4  8 10
> 15 14 12 16                  5  1  9 11
> 再根据主对角线翻转得到：
> 
> 15 14 12 16                    15 13  2  5
> 13  3  6  7   =主对角线翻转=>   14  3  4  1
>  2  4  8 10                    12  6  8  9
>  5  1  9 11                    16  7 10 11
> ```
>
> 

```c++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //水平翻转
        for(int i = 0; i < n/2; i ++){
            for(int j = 0; j < n; j ++){
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        //主对角线翻转
        for(int i = 0; i < n - 1; i ++){
            for(int j = i + 1; j < n; j ++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
```

> 对于原地旋转的话，其实就是四个对应部分的值相互交换了一下，官方讲解太麻烦和复杂了，比如
>
> ```C++
> 5   1  9  11
> 2   4  8  10
> 13  3  6  7
> 15  14 12 16
> ```
>
> 其中发生交换的就是四个相应位置的数，
>
> 5 对应的是 15 16 11
>
> 相应的(i, j)对应的有(n - j - 1, i) 、(n - i - 1, n - j - 1)、 (j, n - i - 1)
>
> 那么我们交换这四个位置的数就可以了，其中我们要注意我们每交换一轮，已经定位好了四个元素的位置，那么n^2个元素，我们只需要 $\frac{n^2}{4}$ 轮即可，我们留意一下，
>
> 可以把这个大矩形分成四个小矩形
>
> ```C++
> 5   1 | 9  11			15  13 | 2  5
> 2   4 | 8  10   		14  3  | 4  1 
> --------------    =>  --------------
> 13  3 | 6  7			12  6  | 8  9
> 15  14| 12 16			16  7  | 10 11	
> ```
>
> 可以发现都是一个小矩形的整体翻转
>
> 对于边长是奇数的情况
>
> ```C++
> 5  | 9 | 11		  5  | 9 | 11
> ----------  	      -----------
> 2    8   10   	  2    8   10	
> ----------    =>    ----------- 
> 13 | 6 | 7		  13 | 6  | 7	
> ```
>
> 分成四个矩形余下来最后四个奇数部位的数，因为中间的数肯定不会旋转，就不用管了，这个时候只需要把边界稍微扩展一下，变成(n+1)/2即可

```C++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i ++) {
            for (int j = 0; j < (n + 1) / 2; j ++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};
```

