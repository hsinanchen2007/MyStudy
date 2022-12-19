### 解题思路
首先，建立一个表格，宽为grid[0].size()+1，高为grid.size()+1的表格，并创建一个长为（grid[0].size()+1）*(grid.size()+1)的并查集，表格中的每个点横坐标为i，纵坐标为j，则可以对表格中的每一个点做一个映射，即
(i,j)对应i*(grid[0].size()+1)+j,对斜杠\，若斜杠连接的表格中的两点在并查集中的根相同，则划分区域数加一，否则将表格中的两点用一次merge()操作。

### 代码

```cpp
class Solution {
class Mu1
{
public:
	int size;
	int*set;
	Mu1()
	{
		size = 10;
		set = new int[size];
		init();
	}
	Mu1(int maxS)
	{
		size = maxS;
		set = new int[size];
		init();
	}
	void init()
	{
		for (int i = 0; i < size; i++)
			set[i] = i;
	}
	void merge(int x, int y)
	{
		set[find(x)] = find(y);
	}
	void change(int maxSize)
	{
		delete[]set;
		set = new int[maxSize];
		size = maxSize;
		init();
	}
	int find(int x)
	{
		if (x == set[x])
			return x;
		else
		{
			return set[x]= find(set[x]);
		}
	}
};
public:
    int regionsBySlashes(vector<string>& grid) {
        Mu1 m = Mu1((grid.size() + 1)*(grid[0].size() + 1));
	for (int j = 0; j <= grid[0].size(); j++)
		m.merge(0, j);
	for (int j = 0; j <= grid.size(); j++)
		m.merge(0, j*(grid[0].size()+1));
	for (int j = 0; j <= grid.size(); j++)
		m.merge(0, j*(grid[0].size()+1) + grid[0].size());
	for (int j = 0; j <= grid[0].size(); j++)
		m.merge(0, grid.size()*(grid[0].size()+1) + j);
	int num=1;
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			if (grid[i].at(j) == '\\')
			{
				if (m.find(i*(grid[0].size() + 1) + j) == m.find((i + 1)*(grid[0].size() + 1) + j + 1))
					num++;
				else m.merge(i*(grid[0].size() + 1) + j, (i + 1)*(grid[0].size() + 1) + j + 1);
			}
			if (grid[i].at(j) == '/')
			{
				if (m.find(i*(grid[0].size() + 1) + j + 1) == m.find((i + 1)*(grid[0].size() + 1) + j))
					num++;
				else m.merge(i*(grid[0].size() + 1) + j + 1, (i + 1)*(grid[0].size() + 1) + j);
			}
		}
	}
	return num;
    }
};
```