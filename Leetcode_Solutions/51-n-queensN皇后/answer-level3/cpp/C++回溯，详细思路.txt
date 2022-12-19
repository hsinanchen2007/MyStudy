https://blog.csdn.net/aa123248135/article/details/94305339

题意理解：
1. 在国际象棋中，皇后所在的行（左右），列（上下），以及左上角、左下角、右上角等8个方向均能够被攻击；
2. 因为题目意思是在N*N的棋盘上布置N个皇后，因此每行每列最多只有一个皇后；

解题思路：
1. 用一个二维数组模拟国际象棋的棋盘，全部初始化为0，当在期盼中布置皇后时，将皇后所能攻击到的范围置1；
```cpp
 //x:皇后所在行下标，y:皇后所在列下标，matrix:模拟棋盘的二维数组
 void put_down_the_queen(int x, int y, vector<vector<int>> &matrix) {
 	//dx[],dy[]分别是模拟八个方向上x,y的移动方向，如dx[0]=-1,dy[0]=0,表示皇后
 	//的向左侧移动一个位置(行x向左移动一个位置，即x-1,列不变y)
	static const int dx[] = { -1, 1,0,0,-1,-1,1,1 };
	static const int dy[] = { 0,0,-1,1,-1,1,-1,1 };
	//令皇后所在的那个位置为1
	matrix[x][y] = 1;
	//因为在N*N的棋盘中，i代表皇后在每个方向上最多能延展的长度，最长的长度为matrix.size()-1;
	for (int i = 1; i < matrix.size(); ++i) {
		//j代表方向，皇后的攻击方向共有8个
		for (int j = 0; j < 8; ++j) {
			//找到延展方向的下标
			int new_x = x + i * dx[j];
			int new_y = y + i * dy[j];
			//若下标在棋盘的范围内，将所在位置置1
			if (new_x >= 0 && new_x < matrix.size() && new_y >= 0 && new_y < matrix.size()) {
				matrix[new_x][new_y] = 1;
			}
		}
	}
```

2. 递归回溯过程
//一行一行的往下布置皇后位置
//k:当前行数，n:棋盘行数，matrix:模拟棋盘数组,res:返回的结果,location:代表皇后位置的一个解
```cpp
void helper(int k, int n, vector<vector<int>>& matrix, vector<vector<string>>& res, vector<string>& location) {
	//若布置到了最后一行，说明棋盘上皇后数量已经达到n,满足条件，将当前解放入结果中
	if (k == n) {
		res.push_back(location);
		return;
	}
	//i为当前第K行的列数
	for (int i = 0; i < n; ++i) {
		//在第K行找到一个可以放置皇后的地方(模拟期盼的数组当前位置为0，表示可以放置皇后的地方)
		if (matrix[k][i] == 0) {
			//存储当前数组值，方便回溯，
			vector<vector<int>> before = matrix;
			//令当前解置'Q',表示放入皇后
			location[k][i] = 'Q';
			//模拟棋盘数组放入皇后，
			put_down_the_queen(k, i, matrix);
			//进行下一行判断
			helper(k + 1, n, matrix, res, location);
			//回溯过程，若第k+1行所有位置都行不通，则找第k行i之后的下一个可行位置放置皇后
			matrix= before;
			location[k][i] = '.';
		}
	}
}
```

 3. 主函数
 //函数的主要逻辑都有了，剩下的就是初始化并返回结果了；
```cpp
 vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> res;
	if (n <= 0)
		return res;
	vector<string> location;
	vector<vector<int>> matrix;
	//初始化matrix和location
	for (int i = 0; i < n; ++i) {
		string s = "";
		vector<int> temp;
		for (int j = 0; j < n; ++j) {
			s.push_back('.');
			temp.push_back(0);
		}
		location.push_back(s);
		matrix.push_back(temp);
	}
	//递归回溯
	helper(0, n, matrix, res, location);
	return res;
}
```