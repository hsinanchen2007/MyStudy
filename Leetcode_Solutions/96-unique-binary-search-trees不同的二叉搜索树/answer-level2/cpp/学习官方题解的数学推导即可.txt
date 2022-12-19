
### 代码

```cpp
class Solution 
{
public:
	int numTrees(int n) 
	{
		vector<int> res(n + 1);
		res[0] = 1;
		res[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			for (int j = 1; j <= i; ++j)
			{
				res[i] += res[j - 1] * res[i - j];
			}
		}
		return res[n];
	}
};
```