### 解题思路
模板题

### 代码

```cpp
class Solution {
public:
	vector<vector<int> > subsets(vector<int>& S) {
		vector<int> out;
		// sort(S.begin(), S.end());
		getSubsets(S, 0, out);
		return res;
	}
	void getSubsets(vector<int>& S, int pos, vector<int>& out) {
		res.push_back(out);
		for (int i = pos; i < S.size(); ++i) {
			out.push_back(S[i]);
			getSubsets(S, i + 1, out);
			out.pop_back();
		}
	}
private:
	vector<vector<int> > res;
};
```