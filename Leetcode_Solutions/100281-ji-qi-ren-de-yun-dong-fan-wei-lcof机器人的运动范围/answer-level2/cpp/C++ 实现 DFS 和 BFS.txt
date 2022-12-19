### DFS
```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> vec ( m, vector( n, 0 ) );
        int count = 0;
        
        dfs( 0, 0, m, n, k, count, vec );

        return count;
    }

    void dfs( int row, int col, int m, int n, int k, int& count, vector<vector<int>>& vec ) {
        if ( row < 0 || row >= m || col < 0 || col >= n )
            return;
        if ( row / 10 + row % 10 + col / 10 + col % 10 > k )
            return;
        if ( vec[row][col] == 1 )
            return;
        
        vec[row][col] = 1;
        ++count;
        
		// 只需判断右、下两个方向即可
        // dfs( row - 1, col, m, n, k, count, vec );
        dfs( row + 1, col, m, n, k, count, vec );
        // dfs( row, col - 1, m, n, k, count, vec );
        dfs( row, col + 1, m, n, k, count, vec );
    }
};
```

### BFS
```cpp
class Solution {
public:
	int get_sum( pair<int, int> P ) {
		int res = 0;
		while ( P.first ) {
			res += P.first % 10;
			P.first /= 10;
		}
		while ( P.second ) {
			res += P.second % 10;
			P.second /= 10;
		}

		return res;
	}
	
    int movingCount(int m, int n, int k) {
		if ( m == 0 || n == 0 )
			return 0;
		
		queue<pair<int, int>> Q;
		vector<vector<bool>> visited( m, vector<bool>( n, false ) );
		// 只需判断右、下两个方向即可
		int dx[2] = { 0, 1 };
		int dy[2] = { 1, 0 };
		int count = 0;

		Q.push( { 0, 0 } );
		while ( !Q.empty() ) {
			auto temp = Q.front();
			Q.pop();
			
			if ( visited[temp.first][temp.second] || get_sum( temp ) > k )
				continue;
			
			++count;
			visited[temp.first][temp.second] = true;
			for ( int i = 0; i < 2; ++i ) {
				int x = temp.first + dx[i];
				int y = temp.second + dy[i];
				
				if ( x >= 0 && x < m && y >= 0 && y < n )
					Q.push( { x, y } );
			}
		}
		
		return count;		
    }
};
```