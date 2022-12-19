### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	int gcd(int x, int y) {
		if (y == 0) {
			return x;
		}
		gcd(y, x%y);
	}
    string gcdOfStrings(string str1, string str2) {
		int len1 = str1.size(), len2 = str2.size();
		int GCDNum = gcd(len1, len2);
		string s;
		if (str1[0] != str2[0])return s;
		while (GCDNum>0) {
			string sTmp = str1.substr(0, GCDNum);
			bool flag = true;
			for (int i = 0; i < len1; i += GCDNum) {
				string ss = str1.substr(i, GCDNum);
				if (ss != sTmp) {
					flag = false;
					break;
				}
			}
			for (int i = 0; i < len2; i += GCDNum) {
				string ss = str2.substr(i, GCDNum);
				if (ss != sTmp) {
					flag = false;
					break;
				}
			}
			if (flag)return sTmp;
			else GCDNum /= 2;
		}
		return s;
    }
};
```