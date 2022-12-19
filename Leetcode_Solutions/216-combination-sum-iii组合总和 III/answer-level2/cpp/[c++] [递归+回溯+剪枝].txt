### 解题思路
本题属于套模板的题目,在套模板的时候需要注意以下几点：
1.每种组合中不存在重复的数字
+ 这就需要我们在递归的时候，将for循环的i写成i=start,每次递归时将其加1传递下去，此时就不会重复使用 之前遍历过的数字。

2.解集不能包含重复的组合
+ 从1到9遍历，不会产生重复的组合

### 代码

```cpp
class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> out;
		sum3Dfs(k, n, 1, out);
		return res;
	}
	void sum3Dfs(int k, int n, int start, vector<int>& out) {
		if (n < 0) {
			return;
		}
		if (n == 0 && out.size() == k) {
			res.push_back(out);
			return;
		}
		for (int i = start; i <= 9; i++) {
			if (n < i) return;	//剪枝
			out.push_back(i);
			sum3Dfs(k, n-i, i+1, out);
			out.pop_back();
		}
		return;
	}
private:
	vector<vector<int>> res;
};
```