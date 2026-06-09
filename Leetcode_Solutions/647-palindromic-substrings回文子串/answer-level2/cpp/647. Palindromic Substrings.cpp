### 解题思路
暴力穷举所有长度里面可能成为回文字符串的数量。
这道题和 5.最长回文字符子串 有直接联系。

### 代码

```cpp
class Solution {
public:
    int countSubstrings(string s) {
        if(s.empty())
        return 0;
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                if(isPalindrome(s, i, j)){
                    count++;
                }
            }
        }
        return count;
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
### 解题思路
5.最长回文字符子串 中心扩展法

### 代码

```cpp
class Solution {
public:
    int countSubstrings(string s) {
        if(s.empty())
        return 0;

        int N = s.size();
        int count = 0;
        for(int center = 0; center <= 2*N - 1; center++){
            count += Length_centerExpand(s, center, N);
        }
        return count;
    }
private:
    int Length_centerExpand(string& s, int& center, int& N){
            int ans = 0;
            int left = center / 2;
            int right = left + center % 2;
            while(left >= 0 && right < N && s[left] == s[right]){
                ans += 1;
                left -= 1;
                right += 1;
            }
            return ans;
    }
};
```

### 解题思路
5.最长回文字符子串 DP

### 代码

```cpp
class Solution {
public:
	//dp(i,j), [i, j]是否构成回文字符串
	//dp(i,j) = (s[i] == s[j] && dp(i+1,j-1))
    //[i, j]区间需要执行不同区间长度的dp操作
    //注意和回文长度状态表达式dp(i,j) = s[i] == s[j] ? dp(i+1,j-1) + 2区别开来
    int countSubstrings(string s) {
		if (s.empty())
			return 0;
        int maxLength = 1;
        int count = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        //遍历方式为：j -> [0, s.size()-1]
        //            i -> [0, j]
        for(int j = 0; j < s.size(); j++){
            for(int i = 0; i <= j; i++){
                if(i == j || (j - i == 1 && s[i] == s[j])){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }
                if(dp[i][j]){
                    count++;
                }
            }
	    }
        return count;
    }
};
```