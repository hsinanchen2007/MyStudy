本题可以认为是寻找一个一个的同心圆，顺序输出每一个同心圆上的点的坐标，可看做是二叉树层次遍历的变形，只不过每个点从最多两个孩子变成了最多四个孩子，我们使用队列的方式保存每个要遍历的点，当进入第一个点的时候，分别去四个方向(孩子)探索，若合适就加入队列，否则就进行下一个。注意由于是矩阵，在进行四个方向遍历的时候，可能出现重复遍历，因此使用一个矩阵标记已经遍历过的点，防止重复。
```
struct Node
{
	Node()
	{
		x = 0, y = 0;
	}
	Node(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	Node& operator=(const Node&m)
	{
		this->x = m.x;
		this->y = m.y;
		return *this;
	}
	int x;
	int y;
};

bool check(int x, int y, vector<vector<int>>&m)
{
	if (x >= m.size() || x < 0 || y >= m[0].size() || y < 0 || m[x][y] == 1)
	{
		return false;
	}
	m[x][y] = 1;		//遍历过一次就设置，防止出现重复
	return true;
}

void compute(vector<vector<int>>&m, vector<vector<int>>&res, Node&start)
{
	vector<vector<int>> dir = { {0,1},{1,0},{0,-1},{-1,0} };    //四个方向
	queue<Node> qu;
	Node current;
	qu.push(start);
	while (!qu.empty())
	{
		current = qu.front();
		qu.pop();
		res.push_back({ current.x,current.y });
		m[current.x][current.y] = 1;
		for (int i = 0; i < dir.size(); i++)                    //遍历所有的孩子
		{
			if (check(current.x + dir[i][0], current.y + dir[i][1], m))
			{
				qu.push(Node(current.x + dir[i][0], current.y + dir[i][1]));
			}
		}
	}
}

vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) 
{
	vector<vector<int>> res;
	if (R <= 0 || C <= 0 || r0 < 0 || c0 < 0 || r0 >= R || c0 >= C)
		return res;
	vector<vector<int>> m(R, vector<int>(C, 0));
	Node start(r0, c0);
	compute(m, res, start);
	return res;
}
```
