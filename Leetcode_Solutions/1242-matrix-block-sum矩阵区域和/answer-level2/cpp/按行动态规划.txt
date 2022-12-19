按行动态规划，ans[i][j] = ans[i][j-1]+vs(mat,j+K,i-K,i+K)-vs(mat,j-K-1,i-K,i+K)
后面的和 == 左边的和 + 新增加的列 - 出去的列

```
class Solution {
	int m, n, sum, x, y;
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        int i, j;
    	for(i = 0; i < m; ++i)
    	{
    		ans[i][0] = sqsum(mat,i,0,K);
	        for(j = 1; j < n; j++)
	        	ans[i][j] = ans[i][j-1]+vs(mat,j+K,i-K,i+K)-vs(mat,j-K-1,i-K,i+K);
	    }
	    return ans;
    }
    
    int vs(vector<vector<int>>& mat, int j, int i0, int i1)
    {
    	for(sum=0 ; i0 <= i1; i0++)
    	{
    		if(inside(i0,j))
    			sum += mat[i0][j];
    	}
    	return sum;
    }
    
    int sqsum(vector<vector<int>>& mat, int i, int j, int K)
    {
        sum = 0;
    	for(x=i-K; x <= i+K; ++x)
    		for(y = j-K; y<= j+K; ++y)
    		{
    			if(inside(x,y))
    				sum += mat[x][y];
    		}
		return sum;
    }
    
    bool inside(int &x, int &y)
    {
    	return (x>=0 && x<m && y>=0 && y<n);
    }
};

```
