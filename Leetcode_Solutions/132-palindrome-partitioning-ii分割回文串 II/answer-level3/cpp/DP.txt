利用动态规划，用二维数组来表示是否是回文字符串，i，j代表子串的头部和尾巴。
如字符串"aab"
再建立一个minCut函数，用来保存最小切割次数，并初始化
index       0  1   2  3  
            a  a   b
minCut      2  1   0 -1 
我从尾部开始遍历，取几个点来说明一下，当i=2,j=2时，为单个回文字符，那么状态是不变的，
如果i=0,j=1, 那么可以看出i=0时的最小切割次数就是由 j=2的位置的最小切割次数+1得到，
由此可以有 minCut[i]=min(minCut[j+1]+1,minCut[i])做比较获得。
下面贴上代码：


class Solution {
public:
	int minCut(string s) {
		if (s.empty())return 0;
		vector<vector<bool>>palin(s.size(), vector<bool>(s.size(), false));
		vector<int>minCut(s.size() + 1, 0);
		for (int i = 0; i <= s.size(); i++)
			minCut[i] = s.size() - i - 1;
		for (int i = s.size() - 1; i >= 0; i--) {
			for (int j = i; j < s.size(); ++j) {
				if (s[i] == s[j] && (j - i <= 1 || palin[i + 1][j - 1])) {
					palin[i][j] = true;
					minCut[i] = min(minCut[j + 1] + 1, minCut[i]);
				}
			}
		}
		return minCut[0];
	}
};