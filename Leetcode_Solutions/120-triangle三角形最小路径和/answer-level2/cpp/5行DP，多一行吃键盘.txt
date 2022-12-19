```
    int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		for (int h = n - 2; h >= 0; h--)
			for (int i = 0; i < h + 1; i++)
				triangle[h][i] += min(triangle[h+1][i], triangle[h + 1][i + 1]);
		return triangle[0][0];
    }
```
