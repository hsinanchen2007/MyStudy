class Solution {
public:
 /* 通过N获得对应的行列坐标(row,col) */
pair<int, int> getPos(int n,int N) {
	int value = 0;
	for (int row = N - 1; row >= 0; row--) {
		if (N % 2 == 0) {
			if (row % 2 == 0) {
				for (int col = N - 1; col >= 0; col--) {
					value++;
					if (value == n)
						return { row,col };
				}
			} else {
				for (int col = 0; col <= N - 1; col++) {
					value++;
					if (value == n)
						return { row,col };
				}
			}
		} else {
			if (row % 2 == 1) {
				for (int col = N - 1; col >= 0; col--) {
					value++;
					if (value == n)
						return { row,col };
				}
			}
			else {
				for (int col = 0; col <= N - 1; col++) {
					value++;
					if (value == n)
						return { row,col };
				}
			}
		
		}
	}
	return { -1,-1 };
}

int snakesAndLadders(vector<vector<int>>& board) {	
	int step = 0;
	int N = board.size();
	set<int> s;
	queue<int> Q;
	vector<vector<int>> visited(N, vector<int>(N, 0));

	Q.push(1);
	visited[N-1][0] = 1;
	while (!Q.empty()) {
		step++;
		int size = Q.size();

		/* 遍历第step趟 */
		for (int i = 0; i < size; i++) {
			int S = Q.front();
			Q.pop();

			/* S的下一目的地有6种可能 */
			for (int j = 1; j <= 6 && S + j <= N*N; j++) {
				/* 下一可能目的地 */
				int next = S + j; 
				if (next == N*N) {
					return step;
				}
				/* 下一目的地的行列坐标 */
				pair<int,int> p = getPos(next,N);
				int r = p.first;
				int c = p.second;

				/* 判断对应的目的地是否有梯子或者蛇 */
				if (board[r][c] == -1 && visited[r][c] == 0) {
					Q.push(next); //没有梯子，目的地就是此方格
					visited[r][c] = 1;
				} else if(board[r][c] != -1){
					if (board[r][c] == N*N) {
						return step;
					}
					next = board[r][c];
					p = getPos(next, N);
					if (visited[p.first][p.second] == 0) {
						Q.push(board[r][c]); //有梯子，目的地就是梯子或者蛇的另一头，此种计算支持不能连续跳跃
						visited[p.first][p.second] = 1;
					}
					
				}
			}
		}
	}
	return -1;
}
};