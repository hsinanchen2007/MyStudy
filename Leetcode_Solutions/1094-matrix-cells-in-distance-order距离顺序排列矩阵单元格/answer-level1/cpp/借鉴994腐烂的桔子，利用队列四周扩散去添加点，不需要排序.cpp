```
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		vector<vector<int>> m;
	vector<vector<int>> flag(R, vector<int>(C, 0));
	queue<pair<int, int>>q;
	q.push({ r0, c0 });
	m.push_back({ r0, c0 });
	flag[r0][c0] = 1;
	vector <int>x = { -1, 0, 1, 0 };
	vector <int>y = { 0, 1,0, -1 };
	while (!q.empty())
	{
		int qsize = q.size();
		for (int i = 0; i < qsize; i++)
		{
			pair<int, int> cur = q.front();
			q.pop();
			for (int j = 0; j < 4;j++)
			{
				int x1 = cur.first + x[j];
				int y1 = cur.second + y[j];
				if (x1 >= 0 && x1 < R&&y1 >= 0 && y1 < C&&flag[x1][y1] == 0)
				{
					q.push({ x1, y1 });
					m.push_back({x1, y1});
					flag[x1][y1] = 1;
				}
			}
		}

	}
	return m;

    }
};
```
