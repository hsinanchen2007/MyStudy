### 思路
1. 对每一行的座位安排进行状态压缩
2. 检测其座椅是否正常，以及学生是否相邻
3. 对于合法的座位安排，可以计算出这一行能安排的学生数量
4. 学生相邻检测，除了本行之内的，仅与上一行相关
5. 对于上一行和这一行的所有安排组合之后的合法安排，可以保存各种组合的最大值
6. 令 `dp[i][j]` 表示第 `i` 行的 `j` 种安排方式下，前 `i` 行能安排的学生数量
7. 那么第 `i` 行的 `j` 种安排方式的数量就等于 `i - 1` 行所有合法排列中最大的数量 + 第 `i` 行的学生数量
8. 即：$dp[i][j] = max(dp[i][j], dp[i-1][k] + count_i)$

### 答题
```C++
class Solution {
public:
	int getCount(int n)	// 这种安排下的人数
	{
		bitset<8> bs(n);
		return bs.count();
	}

	bool checkChair(vector<vector<char>>& seats, int row, int n)
	{	// 检查椅子是否正常
		bitset<8> bs(n);
		for (int i = 0; i < seats[row].size(); i++)
		{
			if (seats[row][i] == '#' && bs[i] == 1) return false;
		}
		return true;
	}

	bool checkValid(int n)
	{	// 检查左右是否相邻，如果传入 j | k 可以根据题意检测两行是否相邻
		bitset<8> bs(n);
		for (int i = 1; i < 8; i++)
		{
			if (bs[i] == 1 && bs[i - 1] == 1) return false;
		}
		return true;
	}

	int maxStudents(vector<vector<char>>& seats)
	{
		int ans = 0;
		vector<vector<int>> dp(seats.size(), vector<int>(1 << seats[0].size(), 0));

		for (int i = 0; i < seats.size(); i++)
		{
			for (int j = 0; j < (1 << seats[0].size()); j++)
			{
				if (!checkChair(seats, i, j)) continue;
				if (!checkValid(j)) continue;
				int cnt = getCount(j);
				if (i == 0)
				{
					dp[i][j] = cnt;
				}
				else
				{
					for (int k = 0; k < (1 << seats[0].size()); k++)
					{
						if (!checkValid(j | k)) continue;
						dp[i][j] = max(dp[i][j], dp[i - 1][k] + cnt);
					}
				}
				ans = max(ans, dp[i][j]);
			}
		}
		return ans;
	}
};
```



### 致谢

学习自 「[简洁清晰的状态dp](https://leetcode-cn.com/problems/maximum-students-taking-exam/solution/jian-ji-qing-xi-de-zhuang-tai-dp-by-newbie-19/)」

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

