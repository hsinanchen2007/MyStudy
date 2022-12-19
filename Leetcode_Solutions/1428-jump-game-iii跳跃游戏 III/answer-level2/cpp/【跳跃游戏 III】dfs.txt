### 思路
1. 从起点开始找一条路径到终点
2. 使用dfs套路即可
3. 方向为 `i + arr[i]` 和 `i - arr[i]`

### 答题
```C++
void dfs(vector<int>& arr, int i, vector<bool>& vi, bool& ans)
{
	if (ans) return;
	if (i < 0 || i >= arr.size()) return;
	if (vi[i]) return;
	vi[i] = true;
	if (arr[i] == 0)
	{
		ans = true;
		return;
	}
	dfs(arr, i + arr[i], vi, ans);
	dfs(arr, i - arr[i], vi, ans);
}

bool canReach(vector<int>& arr, int start) 
{
	bool ans = false;
	vector<bool> vi(arr.size(), false);
	dfs(arr, start, vi, ans);
	return ans;
}
```



### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

