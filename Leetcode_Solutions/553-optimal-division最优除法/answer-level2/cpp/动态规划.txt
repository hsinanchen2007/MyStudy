```c++
class Solution {
public:
	string expression(vector<vector<vector<char> > > &c_pos, vector<int>& nums, int left, int right, bool maxormin) {
		string result;
		if (left == right) {
			stringstream ss;
			ss << nums[left];
			ss >> result;
			return result;
		}
		else if (left == right - 1){
			string tmp1, tmp2;
			stringstream ss1, ss2;
			ss1 << nums[left];
			ss2 << nums[right];
			ss1 >> tmp1;
			ss2 >> tmp2;
			result = tmp1 + "/" + tmp2;
			return result;
		}
		char k = c_pos[left][right][maxormin];
		string s1 = expression(c_pos, nums, left, k, maxormin);
		string s2 = expression(c_pos, nums, k + 1, right, !maxormin);
		if (k + 1 == right) {
			result = s1 + "/" + s2;
		}
		else result = s1 + "/" + '(' + s2 + ')';
		return result;
	}
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
		vector<vector<vector<double> > > dp(n, vector<vector<double> >(n, vector<double>(3)));
		vector<vector<vector<char> > > c_pos(n, vector<vector<char> >(n, vector<char>(2, -1)));//括号位置 -1表示不打括号 
		for (int i = 0; i < n; ++i) {
			dp[i][i][0] = nums[i];
			dp[i][i][1] = nums[i];//1存最小值 
		}
		for (int i = 0; i < n - 1; ++i) {
			dp[i][i + 1][0] = dp[i][i + 1][1] = (double)nums[i] / nums[i + 1];
		}
		for (int j = 2; j < n; ++j) {
			for (int i = j - 2; i >= 0; --i) {
				//cout << i << ' ' << j << ":";
				dp[i][j][0] = -1e9;
				dp[i][j][1] = 1e9;
				for (int k = i; k < j; ++k) {
					double max_r = dp[i][k][0] / dp[k+1][j][1], min_r = dp[i][k][1] / dp[k+1][j][0];
					if (max_r > dp[i][j][0]) {
						dp[i][j][0] = max_r;
						c_pos[i][j][0] = k; 
					}
					if (min_r < dp[i][j][1]) {
						dp[i][j][1] = min_r;
						c_pos[i][j][1] = k; 
					}
				}
				//cout << dp[i][j][0] << ',' << dp[i][j][1] << endl;
			}
		}
		return expression(c_pos, nums, 0, n - 1, 0);
    }
};
```