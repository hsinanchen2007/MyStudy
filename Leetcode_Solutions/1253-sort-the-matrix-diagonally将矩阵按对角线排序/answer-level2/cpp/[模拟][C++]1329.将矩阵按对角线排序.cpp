### 解题思路
桶排，模拟

### 代码

```cpp
class Solution {
public:
	int n,m,x,y;
	int bucket[105];
	vector< vector<int> > diagonalSort(vector< vector<int> >& mat) {
		n=mat.size();
		m=mat[0].size();
		for (int i=0;i<m;++i)
		{
			memset(bucket,0,sizeof(bucket));
			x=0;y=i;
			while (x<n&&y<m)
			{
				++bucket[mat[x][y]];
				++x; ++y;
			}
			x=0;y=i;
			for (int j=1;j<=100;++j)
			{
				while (bucket[j])
				{
					mat[x][y]=j;
					--bucket[j];
					++x; ++y;
				}
			} 
		} 
		for (int i=1;i<n;++i)
		{
			memset(bucket,0,sizeof(bucket));
			x=i,y=0;
			while (x<n&&y<m)
			{
				++bucket[mat[x][y]];
				++x; ++y;
			}
			x=i;y=0;
			for (int j=1;j<=100;++j)
			{
				while (bucket[j])
				{
					mat[x][y]=j;
					--bucket[j];
					++x; ++y;
				}
			}
		}
		return mat;
	}
};
```