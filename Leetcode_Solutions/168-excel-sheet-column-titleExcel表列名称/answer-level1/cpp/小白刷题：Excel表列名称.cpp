从1开始计数略别扭，取余也要考虑0的情况，不如全部变为从0开始计数

代码：
```
class Solution {
public:
	string convertToTitle(int n) {
        n--;
		string s = "";
		while (n >= 0) {
			s.insert(0, 1, (char)(n % 26 + 65));
			n /= 26;
            n--;
		}
		return s;
	}
};
```
