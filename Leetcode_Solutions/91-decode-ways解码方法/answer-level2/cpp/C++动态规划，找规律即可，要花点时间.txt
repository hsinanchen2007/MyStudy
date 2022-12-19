 以下思路都是我举例子总结出来的，思路：
 1.当0出现在开头，不合法，返回0；
 2.建立一个比字符串s长度大1的dp数组，dp数组元素是一个个的pair结构体，first是截至当前位置的字符串的解码方式个数，second是这些解码方式中结尾字母由一个数字表示的个数；
 3.可知dp[1] = 1，然后遍历字符串s的每个位置i，同时更新每个位置i的dp[i]（把i-1和i字符组成的子串称为tmp）：
 （1）若tmp中未出现数字0：
		·如果tmp字符串对应的数字大于26，则新位置i的解码方式个数等于位置i-1的解码方式个数，dp[i].first = dp[i - 1].first，也就是简单地将位置i的数字单独表示一个字母。新位置的second就等于新位置的解码方式个数，dp[i].second = dp[i].first；
		·否则，dp[i].first = dp[i - 1].first + dp[i - 1].second，dp[i].second = dp[i - 1].first
 （2）若tmp == “00”，不合法，函数结束，返回0
 （3）若tmp的第二个字符为0，第一个字符不为0：
		·如果tmp字符串对应的数字大于26，不合法，函数结束，返回0
		·否则，新位置i的解码方式个数就等于位置i-1的解码方式中结尾为单个数字的情况，即那个数字加上0表示一个字母，dp[i].first = dp[i - 1].second，这种情况下，没有结尾为单个数字的情况，dp[i].second = -1
 （4）若tmp的第一个字符为0，第二个字符不为0：
		·这种情况，tmp后一个数字无法与前面那个0组成字母，因为不合法，所以只能后面那个数字单独表示一个字母，所以dp[i].first = dp[i - 1].first，dp[i].second = dp[i].first
 
    至此，所有情况都列举出来了，等遍历完字符串s，dp数组也就计算完毕，返回dp.back().first即可。

```
class Solution {
public:
	int numDecodings(string s) {
		size_t len = s.size();
		if (s.front() == '0') { return 0; }
		if (len == 1) { return 1; }
		vector<pair<int, int> > dp(len+1);
		dp[1] = {1, 1};
		for (size_t i = 2; i <= len; ++i) {
			string tmp = s.substr(i - 2, 2);
			if (tmp == "00") { return 0; }
			if (tmp[1] == '0') {
				if (26 < atoi(tmp.c_str())) { return 0; }
				else {
					dp[i].first = dp[i - 1].second;
					dp[i].second = -1; // 这种情况没有second项
				}
			}
			if (tmp[0] == '0') {
				dp[i].first = dp[i - 1].first;
				dp[i].second = dp[i].first;
			}
			else if(tmp[1] != '0' && tmp[0] != '0') {// 然后是tmp中没有0的情况
				if (26 < atoi(tmp.c_str())) {
					dp[i].first = dp[i - 1].first;
					dp[i].second = dp[i].first;
				}
				else {
					dp[i].first = dp[i - 1].first + dp[i - 1].second;
					dp[i].second = dp[i - 1].first;
				}
			}
		}
		return dp.back().first;
	}
};

```
