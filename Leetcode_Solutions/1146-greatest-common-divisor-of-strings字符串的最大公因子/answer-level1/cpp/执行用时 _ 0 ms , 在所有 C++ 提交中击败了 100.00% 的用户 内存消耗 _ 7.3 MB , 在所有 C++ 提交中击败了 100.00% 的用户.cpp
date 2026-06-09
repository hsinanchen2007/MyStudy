### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	string gcdOfStrings(string str1, string str2) {
		if (str1.size()<str2.size()) {
			swap(str1, str2);
		}
		if ((str1[0]!=str2[0])||(str1.find(str2)==string::npos)) {
			return "";
		}
		int m = str1.size(), n = str2.size();
		int x = 1;
		for(int i = 1; i <= n;i++) {
			if ((m%i==0)&&(n%i==0)) {
				x = i;
			}
		}
		string temp = str1.substr(x);
		while (temp.size()>0) {
			if (temp.find(str1.substr(0, x)) == string::npos) {
				return "";
			}
			temp = temp.substr(x);
		}
		

		return str1.substr(0, x);

	}
};
```