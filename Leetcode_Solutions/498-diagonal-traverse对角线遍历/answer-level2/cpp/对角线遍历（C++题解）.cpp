### 解题思路
1.做一个4x4的测试样例。
	[
		[ 1, 2, 3, 4],
		[ 5, 6, 7, 8],
		[ 9,10,11,12],
		[13,14,15,16]
	]

2.写出输出结果的索引值，找规律。
    //(0,0)     
    //(0,1) (1,0)  
    //(2,0) (1,1) (0,2)   
    //(0,3) (1,2) (2,1) (3,0) 
    //(3,1) (2,2) (1,3) 
    //(2,3) (3,2)  
    //(3,3)  
发现它们的和是从0~6，也就是最大索引值的和。
对于奇数行，行是最大索引。对于偶数行，列是最大索引。

3.定义和变量i，目标行索引a，目标列索引b，写出它们之间的关系。
	i=0,a=0,b=0//a,b的最小值为0
	i=1,b=1,a=0
	i=2,a=2,b=0
	i=3,b=3,a=0
	i=4,a=3,b=1//i<m时，a=i，否则a=m-1
	i=5,b=3,a=2//i<n时，b=i，否则b=n-1
	i=6,a=3,b=3

### 代码

```cpp
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {        
       		vector<int> ans;
		int m = matrix.size ();//二维数组的size返回的是什么？行数
		if (m == 0)return ans;
		int n = matrix[0].size ();//列数
		if (n == 0)return ans;

        int a = 0, b = 0;
		bool flag = true;
		for (int i = 0; i<=(m-1+n-1); i++){//0~6
			if (flag) {
				a =(i>= m) ? (m - 1) : i;
				b = i - a;
				while (a >= 0 && b<n) {
					ans.push_back (matrix[a][b]);
					a--;
					b++;
				}
				flag = false;
			}
			else //当i=3时
			{
				b =(i>= n) ? (n - 1) : i;
				a = i - b;
				while (b >= 0 && a<m) {
					ans.push_back (matrix[a][b]);
					b--;
					a++;
				}
				flag = true;
			}
		}

        return ans;
    }

};
```