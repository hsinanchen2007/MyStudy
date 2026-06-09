### 解题思路
主要思想是利用dfs搜索来进行求解的

### 代码

```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) {
        int A[4] = { -1,1,0,0 };
# 		int B[4] = { 0,0,-1,1 };
		int visit[100][100] = {0};
		int x;
		int y;
		int a;
		int b;
		int c;
		int d;
		int count = 0;
		queue<pair<int, int>>q;
		q.push(pair<int, int>(0, 0));
		visit[0][0] = true;
		count++;
		cout << "count进入循环前: " << count << endl;
		while (!q.empty())
		{
			pair<int, int> p = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				if ((p.first) + A[i] < m && (p.first) + A[i] >= 0 && (p.second) + B[i] >= 0 && (p.second) + B[i] < n && visit[(p.first) + A[i]][(p.second) + B[i]] == 0)
				{
					x = p.first + A[i];
					y = p.second + B[i];
					cout << "x,y= " << x << y << endl;
					visit[x][y] = 1;
					if (x >= 10)
					{
						a = x % 10;
						b = x / 10;
						if (y >= 10)
						{
							c = y % 10;
							d = y / 10;
						}
						else
						{
							c = y;
							d = 0;
						}
					}
					else
					{
						a = x;
						b = 0;
						if (y >= 10)
						{
							c = y % 10;
							d = y / 10;
						}
						else
						{
							c = y;
							d = 0;
						}
					}
					if ((a + b + c + d) <= k)
					{
						cout << "abcdsum: " << a + b + c + d << endl;
						count++;
						cout << "here：" << count << endl;
						q.push(pair<int, int>(x, y));
					}
				}
			}
		}
		return count;
    }
};
```