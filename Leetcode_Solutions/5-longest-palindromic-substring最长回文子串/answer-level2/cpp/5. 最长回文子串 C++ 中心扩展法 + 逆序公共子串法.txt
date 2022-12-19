两种解法：
1.中心扩展法
2.逆序公共子串法

1.中心扩展法
遍历每个字符，从该字符的两端进行扩展，寻找回文的最长长度

```cpp
class Solution {
public:

	int	getlongestLength(int left, int right, string s)
	{
		int l = left;
		int r = right;
		//这里的写法不是很好，当相等是，对索引多执行了一次操作
		while ((l >= 0) && (r < s.size()) && (s[l] == s[r]))
		{
			l--;
			r++;
		}

		return r - l -1;
	}

	string longestPalindrome(string s) {

		if (s.size() <= 1) {
			return s;
		}

		int longest = 0;
		int length1 = 0;
		int length2 = 0;
		int start = 0;
		int end = 0;
		int maxLen = 0;
		string maxStr;
		for (int i = 0; i < s.size(); i++) {
			
			length1 = getlongestLength(i,i,s);
			length2 = getlongestLength(i, i+1, s);
			if (maxLen < max(length1, length2)) {
				maxLen = max(length1, length2);
				start = i - (maxLen-1) / 2;
				end = i+ maxLen / 2;
			}
		}
		maxStr = s.substr(start, maxLen);
		return maxStr;

	}
};
```

2.逆序公共子串法
回文子串一定满足逆序后与原子串相同，因此可以求逆序的最长公共子串。但是最长公共子串不一定是回文的，如下例：caaefdaac ，caa与aac是最长公共子串，但是不是回文，因此需要判断是否是回文。

```cpp
class Solution {
public:
    bool judgePalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                return false;
            }
        }

        return true;
    }

    string longestPalindrome(string s)
    {
        if (s.empty()) {
            return "";
        }

        string rs = string(s.rbegin(), s.rend());
        vector<vector<int>> dp = vector<vector<int>>(s.size() + 1, vector<int>(s.size() + 1, 0));
        string result = "";
        int maxlen = 0;
        int maxi = 0;
        int maxj = 0;

        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[i].size(); j++) {
                if (s[i - 1] == rs[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }

                if (maxlen < dp[i][j]) {
                    int begin = i - dp[i][j];
                    string tmps = s.substr(begin, dp[i][j]);
                    if (judgePalindrome(tmps)) {
                        maxlen = dp[i][j];
                        result = tmps;
                    }
                }
            }
        }

        return result;
    }
};
```
