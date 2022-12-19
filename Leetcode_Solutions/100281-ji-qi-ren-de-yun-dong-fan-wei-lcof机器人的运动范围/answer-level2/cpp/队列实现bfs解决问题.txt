### 解题思路
一个简单的BFS问题，通过BFS算法求出所有联通的区域（可达区域）
使用队列储存后面要访问的节点，游历数组记录已经经过的节点，lambda函数用于判断是否可达，最后每弹出一个队列元素count++即可。

### 代码

```cpp

using namespace std;

class Solution {
public:
    int movingCount(int m, int n, int k) {
bool **isRead = new bool*[m];
		for (int i = 0; i < m; i++)
		{
			isRead[i] = new bool[n];
			for (int j = 0; j < n; j++)
			{
				isRead[i][j] = false;
			}
		}
		
		queue<std::pair<int, int>> tralQue;
		tralQue.emplace(0, 0);
		isRead[0][0] = true;
		int count = 0;
		int x, y;
		while (!tralQue.empty())
		{
			auto curPos = tralQue.front();
			tralQue.pop();
			count++;
			x = curPos.first;
			y = curPos.second;

			auto isAllow = [&](int x, int y) ->bool
			{
				if (x < 0 || y < 0 || x >= m || y >= n)
					return false;
				if (isRead[x][y])
					return false;
				int sum = 0;
				while (x > 0 || y > 0)
				{
					sum += (x % 10 + y % 10);
					x /= 10;
					y /= 10;
				}
				return sum <= k;
			};
			if (isAllow(x + 1, y)) 
			{
				tralQue.emplace(x + 1, y);
				isRead[x + 1][y] = true;
			}
			if (isAllow(x, y - 1))
			{
				tralQue.emplace(x, y - 1);
				isRead[x][y - 1] = true;
			}
			if (isAllow(x - 1, y))
			{
				tralQue.emplace(x - 1, y);
				isRead[x - 1][y] = true;
			}
			if (isAllow(x, y + 1))
			{
				tralQue.emplace(x, y + 1);
				isRead[x][y + 1] = true;
			}
		}

		for (int i = 0; i < m; i++)
		{
			delete[]isRead[i];
		}
		delete[]isRead;
		return count;
    }
};
```