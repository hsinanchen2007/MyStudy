### 代码

```cpp
class Solution {
private:
	vector<vector<int>> res;
	vector<int> tmp;
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		DFS(k, n, 1);
		return res;
	}
	void DFS(int k, int n, int start)
	{
		if (k == 0)
		{
			if (n == 0) res.push_back(tmp);
			return;
		}
		for (int i = start; i <= min(n, 9) && n - i >= 0; i++)
		{
			tmp.push_back(i);
			DFS(k - 1, n - i, i + 1);
			tmp.pop_back();
		}
	}
};
```