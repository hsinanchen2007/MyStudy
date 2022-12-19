
~~目前方法超时，正在思考如何剪枝优化~~

一开始，我想的是暴力做法, 穷举所有情况，四层循环，

```cpp
class Solution1 {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int res = -INT_MAX;

        for (int i = 0 ; i < rows; i++){
            for (int j = i ; j < rows; j++){
                for (int m = 0; m < cols; m++){
                    for (int n = m;  n < cols; n++){
                        int total = calcSums(matrix, i, j, m, n);
                        if ( total == k) return k;
                        if ( total < k) res = max(res, total);

                    }

                }
            }
        }
        return res;

    }
    int calcSums(vector<vector<int>>& matrix, int i, int j, int m, int n){
        int total = 0;
        for (int rs = i; rs <= j; rs++){
            for (int cs = m; cs <= n; cs++){
                total += matrix[rs][cs];
            }
        }
        return total;

    }
};


```

当然肯定会超时，本地运行发现要6.7s。

因为发现有很多子问题被重复计算，因此想到了用动态规划

影响结果的有4个变量，行起始，行结束，列起始，列结束，因此通过4个变量来定义状态

DP[i][j[m][n], 表示从i..j, m..n的和

DP[0][2][0][2], 表示从0-2行,0-2列区域的和

接着状态转移方程

```
if i == j && m == n:  //即固定行固定列
    DP[i][j][m][n] = matrix[i][m]
else if i == j && m != n:  //固定行， 向下移动列
    DP[i][j][m][n] = DP[i][j][m][n-1] + matrix[i][n]
else if i!=j && m == n: //固定列,  向右移动行
    DP[i][j][m][n] = DP[i][j-1][m][n] + matrix[j][m]
else: //沿对角线往下移动
    DP[i][j][m][n] = DP[i][j-1][m][n] + DP[i][j][m][n-1] - DP[i][j-1][m][n-1] + matrix[j][n];
```

前三种情况都比较好理解，第四种情况需要看图

![image.png](https://pic.leetcode-cn.com/aa0d7e89499eb1bcd51a2e3bc6c6dcb4ea999829fecf7c0c1d3dc86da9fad324-image.png)

对应关系为

- DP[i][j-1][m][n] 对应图中1
- DP[i][j][m][n-1] 对应图中2
- DP[i][j-1][m][n-1] 对应图中3

四维数组在stack分配内存，直接stack overflow了。于是用了容器。

```cpp
class Solution2 {
public:

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

        int rows = matrix.size();
        if (rows == 0 ) return 0;
        int cols = matrix[0].size();
        if (cols == 0 ) return 0;
        
        // 状态数组
        //int DP[rows][rows][cols][cols]; // stack-overflow, 爆栈了
        // 在heap上分配

        vector < vector < vector<vector<int>> > > DP(rows, vector<vector<vector<int>>>( rows, vector<vector<int>> (cols, vector<int>(cols, 0) ) ) );

        int res = INT_MIN;
        for (int i = 0 ; i < rows; i++){
            for (int j = i ; j < rows; j++){
                for (int m = 0; m < cols; m++){
                    for (int n = m;  n < cols; n++){
                        if (i == j && m == n){
                            DP[i][j][m][n] = matrix[i][m];
                        } else if ( i == j && m != n){
                            DP[i][j][m][n] = DP[i][j][m][n-1] + matrix[i][n];
                        } else if ( i != j && m == n){
                            DP[i][j][m][n] = DP[i][j-1][m][n] + matrix[j][m];
                        } else {
                            DP[i][j][m][n] = DP[i][j-1][m][n] + DP[i][j][m][n-1] - DP[i][j-1][m][n-1] + matrix[j][n];
                        }
                        if (DP[i][j][m][n] == k) return k;
                        if (DP[i][j][m][n] < k) {
                            res = max(DP[i][j][m][n], res);
                        }
                    }
                }
            }
        }
        return res;

    }

};

```

这个代码运行超时，本地运行100行100列的话大概要0.6秒，倒是比暴力快了十倍。


原本用的的下面方法分配内存，结果扩容时间太久，所以实际代码就是4层嵌套直接分配内存。

```
		vector < vector < vector<vector<int>> > > DP;
		DP.resize( rows );
		for(int i=0; i < rows; i++){
			DP[i].resize(rows);
			for (int j = 0; j < rows; j++){
				DP[i][j].resize(cols);
				for (int k = 0; k < cols; k++){
					DP[i][j][k].resize(cols,0);
				}
			}
		}
```

看到了[C++矩阵暴力求解](https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/solution/c-ju-zhen-bao-li-qiu-jie-by-da-li-wang/), 发现里面的方法和我之前的想法差不多，于是参考了的思想修改了我之前的代码。

我们不再用四维矩阵进行定义状态，而是只用2个维度。

DP[i][j]定义的是 从0..i, 0..j的和

根据下图

![image.png](https://pic.leetcode-cn.com/aa0d7e89499eb1bcd51a2e3bc6c6dcb4ea999829fecf7c0c1d3dc86da9fad324-image.png)

我们的动态转移方程为: DP[i][j] = DP[i-1][j] + DP[i][j-1] - DP[i-1][j-1] + matrix[i][j]

如果我们要求解的区域是 i1..i2, j1..j2, 表示从i1到i2, j1到j2的数组之和，从下图中
 
![image.png](https://pic.leetcode-cn.com/d4098d43824a4044479e287da13497ffd5ba2d5f1633c1047e9b50bc94d3fa3b-image.png)

我们发现要求解DP[i1..i2][j1..j2] ，对应5

- DP[i2][j2] 是最外圈，也就是1
- DP[i1][i2] 是最内圈，也就是4
- DP[i2][j1] 是3，在上侧。
- DP[i1][j2] 是2，在左侧

不难得到 DP[i1..i2][j1..j2] =  DP[i2][j2] - DP[i2][j1] - DP[i1][j2]  + DP[i1][j1];

也就是最外圈减去左侧，减去上侧加上多减的部分就是我们计算的区域。

代码如下

```cpp
class Solution {
public:

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

        int rows = matrix.size();
        if (rows == 0 ) return 0;
        int cols = matrix[0].size();
        if (cols == 0 ) return 0;

        int res = -INT_MAX;
        int DP[rows+1][cols+1];
        for (int i = 0; i < rows + 1; i++){
            DP[i][0] = 0;
        }
        for (int j = 0; j < cols + 1; j++){
            DP[0][j] = 0;
        }
        for (int i = 1 ; i < rows + 1; i++){
            for (int j = 1 ; j < cols + 1; j++){
                DP[i][j] = DP[i-1][j] + DP[i][j-1] - DP[i-1][j-1] + matrix[i-1][j-1];
                //printf("%d-%d:%d\n", i, j, DP[i][j]);
            }
        }
        for (int i1 = 0 ; i1 < rows; i1++){
            for (int i2 = i1+1 ; i2 <= rows; i2++){
                for (int j1 = 0; j1 < cols; j1++){
                    for (int j2 = j1+1;  j2 <= cols; j2++){
                        int total =  DP[i2][j2] - DP[i2][j1] - DP[i1][j2]  + DP[i1][j1];
                        //printf("%d.%d.%d.%d: %d\n",i1,i2,j1,j2,total);
                        if (total == k) return total;
                        if ( total <k ) res = max(total,res);
                    }
                }
            }
        }
        return res;

    }

};
```

代码中，我用的是一个 rows + 1 X cols + 1 。对应上图中外面的0,1,2,3,4,5,6, 求解0-1的面积，就用1-0来算。
