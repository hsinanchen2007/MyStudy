## 思路


从起点 $(x=0,y=0)$ 出发，下一步只能向右或者向下到达第二点，向右则为 $(x+1，y)$ 向下则为 $(x，y+1)$，一直到 $(x=m，y=n)$ 这个点则为结束点视为一条路径。

因此从起点到终点的所有路径总数则为 $2$ 个 以第二个点到终点的路径数的总和。

可以递归求解如下：
```C++ []
class Solution{
	public:
		int uniquePaths(int m, int n){
			if(m <= 0 || n <= 0)
				return 0;
			else if(m == 1  || n == 1)//只能一直向右走或者一直向下走，所以路径数为 1
				return 1;
			else if(m == 2 && n == 2)
				return 2;
			else if((m == 3 && n == 2) || (m == 2 && n == 3))
				return 3;
			int paths = 0;
			paths += uniquePaths(m-1,n);
			paths += uniquePaths(m,n-1);
			return paths;
		}
};
```
但是这种方法会有很多重复计算比如 $7×3$ 的例子：

![image.png](https://pic.leetcode-cn.com/bf1374e902a0a5cd181e99b00b61ebd896456bb80e4c81cad7d9c84e1ccccd6d-image.png)

而且 $7×3$ 的路径总数也可以在计算 $m>=7$ && $n>=3$ 的计算过程中用到。

### 优化

因为 m，n 都不超过 100，因此可以使用二维数组存下已经计算过的路径数可以避免大量的重复计算。

最终实现结果如下：
```C++ []
static int a[101][101]={0};//记录已经计算过的路径，大大提高效率
class Solution{
	public:
		int uniquePaths(int m, int n){
			if(m <= 0 || n <= 0)
				return 0;
			else if(m == 1  || n == 1)
				return 1;
			else if(m == 2 && n == 2)
				return 2;
			else if((m == 3 && n == 2) || (m == 2 && n == 3))
				return 3;
			if(a[m][n] > 0)
				return a[m][n];
			a[m-1][n] =  uniquePaths(m-1,n);
			a[m][n-1] =  uniquePaths(m,n-1);
			a[m][n] = a[m-1][n]+a[m][n-1];
			return a[m][n];
		}
};

```