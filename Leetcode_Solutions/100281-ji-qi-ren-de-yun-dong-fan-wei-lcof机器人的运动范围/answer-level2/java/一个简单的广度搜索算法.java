可能我的小学语文还未毕业，这个题目，理解起来，竟然花费三次提交机会。

理解题目之后，就是非常常规的广度搜索算法了，一个队列搞定。中间坑不少
```
public int movingCount(int m, int n, int k)
	{
		if (m <= 0 || n <= 0 || k < 0)
		{
			return 0;
		}
		boolean[][] tmp = new boolean[m][n];
		Queue<Integer> queue = new LinkedList<>();
		queue.add(0);
		queue.add(0);
		int res = 0;
		while (queue.size() > 0)
		{
			int i = queue.poll();
			int j = queue.poll();

			if (tmp[i][j])
			{
				continue;
			}
			if (sum(i) + sum(j) <= k)
			{
				res++;
				tmp[i][j] = true;
			}
			else
			{
				continue;
			}

			int ni = i + 1;
			int nj = j;
			if (limit(ni, nj, m, n) && !tmp[ni][nj])
			{
				queue.add(ni);
				queue.add(nj);
			}
			ni = i;
			nj = j + 1;
			if (limit(ni, nj, m, n) && !tmp[ni][nj])
			{
				queue.add(ni);
				queue.add(nj);
			}

		}
		return res;
	}

	private int sum(int c)
	{
		int res = 0;
		while (c > 0)
		{
			int t = c % 10;
			res += t;
			c = c / 10;
		}
		return res;
	}

	private boolean limit(int i, int j, int m, int n)
	{
		if (i >= 0 && i < m && j >= 0 && j < n)
		{
			return true;
		}
		return false;
	}
```
