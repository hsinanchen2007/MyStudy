

```cpp
class Solution 
{
public:
	int minimumTotal(vector<vector<int>>& triangle) 
	{
		int m = triangle.size();
		for (int i = 1; i < m; ++i)
		{
			for (int j = 0; j < triangle[i].size(); ++j)
			{
				if (j == 0)
				{
					triangle[i][j] += triangle[i - 1][j];
				}
				else if (j == triangle[i].size() - 1)
				{
					triangle[i][j] += triangle[i - 1][j - 1];
				}
				else
				{
					triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
				}
			}
		}
		return *min_element(triangle[m - 1].begin(), triangle[m - 1].end());
	}
};
```