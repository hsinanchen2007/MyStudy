### 解题思路
代码思路：
1.以每个元素作为回文中心；
2.分两种情况：单数，双数；
3.从可能出现最长序列开始寻找，以返回回文长度缩短寻找区间。

### 代码

```cpp
class Solution {
public:
int n_Palindrome(string s,int n){
	int size = s.size();
	int i = 1;
	while (n - i > -1 && n + i<size&&s[n - i] == s[n + i]){
		i++;
	}
	int j = 0;
	while (n - j - 1 > -1 && n + j<size&&s[n - j - 1] == s[n + j]){
		j++;
	}
	return max(2*i-1,2*j);
}

string longestPalindrome(string s){
	int max = 0;
	string a = "";
	int mid = s.size() / 2;
	int end = mid;
	int num = n_Palindrome(s, mid);
	if (max < num){
		max = num;
		a = s.substr(mid - num / 2, num);
		end = mid - num / 2;
	}
	for (int i = 1; i < end+1; i++){
		int num = n_Palindrome(s, mid - i);
		if (max < num){
			max = num;
			a = s.substr(mid - i - num / 2, num);
			end = mid - num / 2;
		}
		num = n_Palindrome(s, mid + i);
		if (max < num){
			max = num;
			a = s.substr(mid + i - num / 2, num);
			end = mid - num / 2;
		}
	}
	return a;
}
};
```