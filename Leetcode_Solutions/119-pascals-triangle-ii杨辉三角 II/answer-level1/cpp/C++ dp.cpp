### 解题思路
写出5行杨辉三角
1				rowIndex=0
1 1				rowIndex=1
1 2 1			rowIndex=2
1 3 3 1			rowIndex=3
1 4 6 4 1		rowIndex=4
可以发现从rowIndex=2开始，f[i][j]=f[i-1][j-1]+f[i-1][j]
因此O(k)即通过保存上一行的结果，就可以求得下一行

### 代码

```cpp
//O(K)空间复杂度
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> dp;
		for (int i=0;i<=rowIndex;i++)
		{
			dp.push_back(1);//数组随i增大1格
			//当前项等于上一行中的该项和前一项相加
			for (int j=i-1;j>0;j--)
			{
				dp[j] = dp[j - 1]+ dp[j];//dp[j]对应于f[i-1][j],dp[j-1]对应于f[i-1][j-1]
			}
		}
		return dp;
	}
};
```