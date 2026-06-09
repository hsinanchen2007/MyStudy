八皇后问题的推广
所谓八皇后，就是要求棋盘上每行 每列 每一斜行都只有一个皇后
**以vector<int>x  记录第i行的皇后放在第x[i]列**
判断行(第k行)当前列（x[k]）放皇后是否合法为：  
  bool place(int k)
{
	for (int i = 0; i < k; i++) // 之前已经放置的皇后位置
	{
		if (x[i] == x[k] || abs(k - i) == abs(x[k] - x[i]))
			return false;
	}
	return true;
}
**如果当前位置是合法的，就可以递归进行下一行的放置**（最开始从0开始放）

而这里就是在输出上稍微添加了一点，我们可以先保存vector<vector<int>>为每个解法的int部分，即每组x
然后遍历将对应的string[x[i]]转化为'Q'，其他的仍然是.

代码如下：
vector<int>x;
vector<vector<int>>tempans;
int sum;
int N;
bool place(int k)
{
	for (int i = 0; i < k; i++)
	{
		if (x[i] == x[k] || abs(k - i) == abs(x[k] - x[i]))
			return false;
	}
	return true;
}
void quene(int num)
{
	if (num >= N)
	{
		sum += 1;
		vector<int>temp;
		for (int i = 0; i < N; i++)
		{
			temp.push_back(x[i]);
		}
		tempans.push_back(temp);
	}
	else {
		for (int i = 0; i < N; i++)
		{
			x[num] = i;
			if (place(num))
				quene(num + 1);
		}
	}
}
vector<vector<string>> solveNQueens(int n) {
	sum = 0;
	N = n;
	vector<vector<string>> res;
	for (int i = 0; i < n; i++)
		x.push_back(-1);
	quene(0);
	for (int i = 0; i < tempans.size(); i++)
	{
		vector<string>temp;
		for (int j = 0; j < tempans[i].size(); j++)
		{
			string nowans = "";
			for (int k = 0; k < n; k++)
				nowans += '.';
			nowans[tempans[i][j]] = 'Q';
			temp.push_back(nowans);
		}
		res.push_back(temp);
	}
	return res;
}