# 1.暴力枚举
for i 0->size
    for j i->size
		    isPalindrome
```
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1)
        return s;
        int maxLength = 0;
        int L;
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                if(isPalindrome(s, i, j)){
                    if(maxLength < j - i + 1){
                        maxLength = j - i + 1;
                        L = i;
                    }
                }
            }
        }
        return string(s, L, maxLength);
    }
private:
    bool isPalindrome(string &s, int start, int end){
        while(start <= end){
            if(s[start] == s[end]){
                start++;
                end--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
```
# 2.中心扩展
for i 1->size
    Length_centerExpand
		
```
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1)
        return s;
        string temp;
        string ret;
        int maxR = 0;
        int maxC = 0;
        temp.push_back('#');
        for(auto& c : s){
            temp.push_back(c);
            temp.push_back('#');
        }
        for(int i = 1; i < temp.size(); i++){
            int iR = max(maxR, Length_centerExpand(temp, i));
            if(maxR < iR){
                maxR = iR;
                maxC = i;
            }
        }
        for(int i = maxC - maxR; i <= maxC + maxR; i++){
            if(temp[i] != '#'){
                ret.push_back(temp[i]);
            }
        }
        return ret;
    }
private:
    int Length_centerExpand(string &s, int iCenter){
        int ilength = 0;
        int iLeft = iCenter;
        int iRight = iCenter;
        while(--iLeft >= 0 && ++iRight <= s.size()){
            if(s[iLeft] == s[iRight]){
                ilength++;
            }
            else{
                break;
            }
        }
        return ilength;
    }
};
```

# 3.暴力递归（长度）
```
class Solution {
public:
	//F(i,j) [i, j]区间字符串是否是回文
	//F(i,j) == (s[i] == s[j] && F(i+1,j-1))
	//       == (s[i] != s[j] && F(i,j-1))
	//       == (s[i] != s[j] && F(i-1,j))
	int longestPalindrome(string s) {
		if (s.length() <= 1)
			return s.length();

		return palindLength_R(s, 0, s.size() - 1);

	}
private:
	int palindLength_R(string s, int l, int r) {
		if (l > r)
			return 0;
		else if (l == r)
			return 1;
		if (s[l] == s[r]) {
			return palindLength_R(s, l + 1, r - 1) + 2;
		}
		else {
			return max(palindLength_R(s, l + 1, r), palindLength_R(s, l, r - 1));

		}
	}
};
```
# 4.暴力递归优化（长度）
```
class Solution {
public:
	//F(i,j) [i, j]区间字符串是否是回文
	//F(i,j) == (s[i] == s[j] && F(i+1,j-1))
	//       == (s[i] != s[j] && F(i,j-1))
	//       == (s[i] != s[j] && F(i-1,j))
	int longestPalindrome(string s) {
		if (s.length() <= 1)
			return s.length();

		vector<vector<int>> memo(s.size(), vector<int>(s.size(), 1));

		return palindLength_R(s, 0, s.size() - 1, memo);

	}
private:
	int palindLength_R(string s, int l, int r, vector<vector<int>>& memo) {
		if (l > r)
			return 0;
		else if (l == r) {
			memo[l][r] = 1;
			return 1;
		}
		if (s[l] == s[r]) {
			memo[l][r] = palindLength_R(s, l + 1, r - 1, memo) + 2;
			return memo[l][r];
		}
		else {
			memo[l][r] = max(palindLength_R(s, l + 1, r, memo), palindLength_R(s, l, r - 1, memo));
			return memo[l][r];
		}
	}
};
```
# 5.动态规划(长度？)
```
class Solution {
public:
	//F(i,j) [i, j]区间最大回文子串长度(i <= j)
	//F(i,j) == (s[i] == s[j] ? F(i+1,j-1) + 2 : max(F(i,j-1), F(i-1,j))
	//dp(i,j) == (s[i] == s[j] ? dp(i+1,j-1) + 2 : max(dp(i,j-1), dp(i-1,j))
	int longestPalindrome(string s) {
		if (s.length() <= 1)
			return s.length();

		vector<vector<int>> dp(s.size(), vector<int>(s.size(), 1));
		for (unsigned int j = 1; j < s.size(); j++) {
			for (unsigned int i = 0, k = j; k < s.size(); k++, i++) {
				dp[i][k] = (s[i] == s[k] ? dp[i + 1][k - 1] + 2 : max(dp[i][k - 1], dp[i + 1][k]));
				printf("s[%d] == %c, s[%d] == %c, dp[%d][%d] == %d\n", i, s[i], k, s[k], i, k, dp[i][k]);
			}
		}
		return dp[0][s.size() - 1];
	}
};
```
# 5.动态规划(求子串，遍历方式1)
```
class Solution {
public:
	//dp(i,j), [i, j]是否构成回文字符串
	//dp(i,j) = (s[i] == s[j] && dp(i+1,j-1))
    //[i, j]区间需要执行不同区间长度的dp操作
    //注意和回文长度状态表达式dp(i,j) = s[i] == s[j] ? dp(i+1,j-1) + 2区别开来
	string longestPalindrome(string s) {
		if (s.length() <= 1)
			return s;
        int maxLength = 1;
        int start = 0;
		vector<int> dp(s.size(), 0);
        //初始化长度为1和2时候的值
        for(int i = 0; i < s.size(); i++){
            dp[i] = 1;
            if(i + 1 < s.size() && s[i] == s[i+1]){
                dp[i+1] = 1;
                start = i;
                maxLength = 2;
            }
        }
        //求解其他长度是否为回文字符串
		for (int len = 2; len < s.size(); len++) {
			for (int i = 0; i < s.size() - len; i++) {
				dp[i][i+len] = (s[i] == s[i+len] && dp[i+1][i+len-1]);
                //printf("dp[%d][%d] == %d\n", i, j, dp[i][j]);
                if(dp[i][i+len] && maxLength < (len + 1)){
                    maxLength = len + 1;
                    start = i;
                }
			}
		}
		return s.substr(start, maxLength);
	}
}; 
```
# 5.动态规划(求子串，遍历方式2)
```
class Solution {
public:
	//dp(i,j), [i, j]是否构成回文字符串
	//dp(i,j) = (s[i] == s[j] && dp(i+1,j-1))
    //[i, j]区间需要执行不同区间长度的dp操作
    //注意和回文长度状态表达式dp(i,j) = s[i] == s[j] ? dp(i+1,j-1) + 2区别开来
	string longestPalindrome(string s) {
		if (s.length() <= 1)
			return s;
        int maxLength = 1;
        int start = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        //遍历方式为：j -> [0, s.size()-1]
        //            i -> [0, j]
        //初始化：初始化[0,0]
        for(int j = 0; j < s.size(); j++){
            for(int i = 0; i <= j; i++){
                if(i == j || (j - i == 1 && s[i] == s[j])){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }
                if(dp[i][j] && (maxLength < j - i + 1)){
                    maxLength = j - i + 1;
                    start = i;
                }
            }
	    }
        return s.substr(start, maxLength);
    }
}; 
```

