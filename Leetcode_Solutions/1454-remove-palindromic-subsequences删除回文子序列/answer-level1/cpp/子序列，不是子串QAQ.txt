### 解题思路
子序列，不是子串……坑死我了，想了一个多小时硬是没看明白。这就三种可能，因为只有a,b。
如果是子串的话，我写了另一个版本的：

# 子串
```cpp
bool ishuiwen(string s) {//判断是否为回文串
	string rs = s;
	reverse(s.begin(), s.end());

	if (rs == s)return true;

	else return false;
}

int removePalindromeSub(string s) {
	int len = s.length();
	if (len == 0)return 0;

	if (ishuiwen(s))return 1;
	int j = 0;
	int count = 0;//用于计数判断
	string subs;
	while (j < len) {
		for (int i = s.length(); i > 0; i--) {//逐次缩短判断子串是否为回文，是就删除
			subs = s.substr(0, i);
			if (ishuiwen(subs)) {
				s.erase(0,i);
				count++;
				j += i;
				break;
			}
		}
	}	
		return count;
}
```
# 本题：

### 代码

```cpp
class Solution {
public:
    bool isPalindromic(string s){
        string rs = s;
        reverse(s.begin(),s.end());
        return (s==rs);
    }
    int removePalindromeSub(string s) {
        if(s=="")return 0;
        if(isPalindromic(s))return 1;
        else return 2;
    }
};
```