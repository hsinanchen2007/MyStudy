```
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		vector<string> location;//里面是Q和...，有皇后的位置是Q
		vector<vector<int>> mark;//大小为棋盘，皇后及皇后的攻击范围标记为1
		
		//初始化location和mark
		string s(n, '.');
		vector<int> loc(n,0);
		for (int i = 0; i < n;i++)
		{
			location.push_back(s);
			mark.push_back(loc);
		}

		generate(0, n, location, mark, result);
		return result;
	}

private:

	//k:每行有且仅有1个皇后，正在放置第k行的皇后，k从0开始
	//n:n行，共n个王后
	void generate(int k, int n,vector<string>& location,
		vector<vector<int>>& mark, vector<vector<string>>& result)
	{
		if (k==n)//当k=n时，代表完成了所有皇后的放置，将记录皇后位置的二维数组location，push到result中
		{
			result.push_back(location);
			return;
		}
		for (int i = 0; i < n;i++)//按顺序尝试第0至第n列，注意是【列】
		{
			if (mark[k][i]==0)//代表可以放置皇后
			{
				vector<vector<int>> tem_mark = mark;//记录回溯前的mark镜像
				put_down_the_queen(k, i, mark);//放置皇后
				location[k][i] = 'Q';//记录当前皇后的位置

				generate(k + 1, n, location, mark, result);//递归下一行放置

				mark = tem_mark;//将mark赋值为回溯前的状态，
				location[k][i] = '.';//将当前尝试的位置重新赋值为“.”
			}
		}
	}

	//在（x,y）处放置王后，mark[行][列]表示棋盘
	void put_down_the_queen(int x,int y,vector<vector<int>>& mark)
	{
		mark[x][y] = 1;//在（x,y）放置王后
		//方向数组，八个方向。放置一个王后后，其周围八个方向均不能再放置王后
		static const int dx[] = {-1,-1,-1,0,0,1,1,1};
		static const int dy[] = {-1,0,1,-1,1,-1,0,1};
		for (int i = 1; i < mark.size();i++)//每个方向向外延伸1至最多N-1
		{
			for (int j = 0; j < 8;j++)//八个方向
			{
				int new_x = x + dx[j] * i;//dx,dy合起来可以理解为类似于斜率的东西
				int new_y = y + dy[j] * i;
				if (new_x >= 0 && new_x < mark.size() && new_y >= 0 && new_y < mark.size())//边界
				{
					mark[new_x][new_y] = 1;
				}
			}
		}
	}

};
```
