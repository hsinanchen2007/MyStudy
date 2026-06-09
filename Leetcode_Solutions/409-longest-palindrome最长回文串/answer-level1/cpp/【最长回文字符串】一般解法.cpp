### 解题思路
1，ASII　65-122,故开字典数组58
2,构成回文的条件是偶数字符，或者奇数字符减一
3，需要判断是否有奇数字符，以此作为中心字符

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
    vector<int> a(58, 0);
	int len = 0;
	bool flag = false;
	for (int i = 0; i < s.length(); i++)
		a[s[i] - 'A'] ++;
	for (int i = 0; i < a.size(); i++) {
		if (!(a[i] & 1))
			len += a[i];
		else if ((a[i] & 1))
		{
			len += (a[i] - 1);
			flag = true;
		}
	}
	return len+flag;
    }
};
```