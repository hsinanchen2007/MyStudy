class Solution {
public:
	vector<vector<int>> res;
	void fun(int m, int n, int k,  vector<int> re) {
		for (int i = m; i < n - k + 2; i++) {
			if (k == 0) {
				res.push_back(re);
				return;
			}
			re.push_back(i);
			fun(i + 1, n, k - 1, re);
			re.pop_back();
		}
	}
	vector<vector<int>> combine(int n, int k) {
		vector<int> re;
		fun(1, n, k,  re);
		return res;
	}
};