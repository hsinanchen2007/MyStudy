### 解题思路
此处撰写解题思路
1. 设字符串s1(长度m),字符串s2(长度n)
2. 以矩阵dp(m*n)记录编辑操作
3. 由s1与s2末端字符开始比对
	1. 当末端字符相等，则当前字符无需编辑，那么dp[m][n] = dp[m-1][n-1]
	2. 当末端字符不相等
		1. 修改S或者T的末端元素，使得二者末端相等，操作+1，则：
			  dp[m][n] = dp[m-1][n-1] + 1
		2. 删除S或者T的末端元素，使得二者末端相等，操作+1，两种操作分别为：
			- dp[m][n] = dp[m][n-1] + 1
			- dp[m][n] = dp[m-1][n] + 1
		3. 在S或T的末端添加元素，使得二者末端相等，操作+1，此时对其余字符编辑距离同上：
			- dp[m][n] = dp[m][n-1] + 1
			- dp[m][n] = dp[m-1][n] + 1
动态规划方程为：
![20180828165947162.png](https://pic.leetcode-cn.com/eb07c3a4cc9fd8af46a46b323770e254a41872ce86af206084aa1490d90da67c-20180828165947162.png)



### 代码

```cpp

class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1_len = word1.length();
		int w2_len = word2.length();
		int i = 0, j = 0;
		vector<vector<int>> arr(w1_len + 1, vector<int>(w2_len + 1));
		for (int i = 0; i < w1_len + 1; i++)
		{
			for (int j = 0; j <w2_len + 1; j++)
			{
				if (i == 0){arr[i][j] = j;}
				else if (j == 0){arr[i][j] = i;}
				else if (word1[i - 1] == word2[j - 1])
				{
					arr[i][j] = arr[i - 1][j - 1];
				}
				else
				{
					arr[i][j] = 1 + min(min(arr[i][j - 1], arr[i - 1][j]), arr[i - 1][j - 1]);
				}
			}
		}

		return arr[w1_len][w2_len];
    }
};
```