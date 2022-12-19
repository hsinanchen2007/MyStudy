### 解题思路
0ms,7mb.内存占用有点多，不知道这个100%咋计算的。使用DFS时最少用5.8MB

### 代码

```cpp
// 计算数位之和
int get(int x,int y)
{
	int num = 0;
	while (x != 0)
	{
		num += x % 10;
		x = x / 10;
	}
	while (y != 0)
	{
		num += y % 10;
		y = y / 10;
	}
	return num;
}	
// 广度优先遍历
class Solution {
public:
	int movingCount(int m, int n, int k) {
		// 建立M*N矩阵，vector套vector,后面参数表示 m 个vector容器,每个容器大小为n
		vector<vector<int>>v(m,vector<int>(n));

		return bfs(0, 0, m, n,k,v);

	}
typedef pair <int, int> Dot;			// 定义pair<int,int>类型名为Dot
private:
	int bfs(int x, int y, int m, int n,int k, vector<vector<int>>&v) {
		//判断当前结点是否有效，有效则入队
		if (x >= m || y >= n || v[x][y]==1 || get(x, y) > k||k<0)
			return 0;
		v[x][y] = 1;
		queue<pair<int, int>>Q;		// pair也是一种模板类型，类似容器，分为first与second访问,使用时必须提供好类型名，二者不必相同
		Q.push(make_pair(x, y));	// make_pair 使成pair函数
		int sum = 1;
		while (!Q.empty())
		{
			Dot a = Q.front();			//取队首元素
			Q.pop();					//pop队首元素,该元素已经过判定，下判定右方向与下方向元素
			Dot a_right,a_down;			//得到右方向元素和下方向元素
			a_right.first = a.first;
			a_right.second = a.second+1;

			a_down.first = a.first + 1;
			a_down.second = a.second;

			if (a_right.first >= m || a_right.second >= n || v[a_right.first][a_right.second] || get(a_right.first, a_right.second) > k)
				;
			else
			{
				v[a_right.first][a_right.second] = 1;
				Q.push(a_right);
				sum++;
			}
			if (a_down.first >= m || a_down.second >= n || v[a_down.first][a_down.second] || get(a_down.first, a_down.second) > k)
				;
			else
			{
				Q.push(a_down);
				v[a_down.first][a_down.second] = 1;
				sum++;
			}
		}
		return sum;
		
	}
};
```