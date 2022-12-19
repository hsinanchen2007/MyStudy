一开始空字符串或者只有空格的字符串没排除，搞死我了。
后面判断超过INT_MAX或者小于等于INT_MIN的也很繁。

```C++ []
class Solution {
public:
	int myAtoi(string str) {
		int pos = str.find_first_not_of(" ");
		if (pos == -1)	//表明字符串只有空格或者为空
			return 0;
		str = str.substr(pos);
		int idx = 0;
		bool flag = false;
		if (str[0] == '+' || str[0] == '-') {
			idx++;
			if (str[0] == '-')
				flag = true;
		}
		str = str.substr(idx);
		pos = str.find_first_not_of("0123456789");
		str = str.substr(0, pos);
		int res = 0;
		int max = INT_MAX / 10;
		for (auto c : str) {
			int digit = c - '0';
			if (res > max || (res == max && digit > 7)) {	//大于最大值，或者小于等于最小值
				if(flag)
					return INT_MIN;
				else
					return INT_MAX;
			}
			res = res * 10 + digit;
		}
		if (flag)
			res = -res;
		return res;
	}
};
```
