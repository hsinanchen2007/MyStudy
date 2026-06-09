### 解题思路
深搜+回溯。83%与100%

### 代码

```cpp
// 输入的字符串长度至少是4吧
// 一定要把字符串分成四部分，所以可能会用到递归或者深搜回溯
// 深度是4，每次搜索的长度变化
// 每一段的大小必须在0~255之间
// 考虑特殊的ip情况0.0.0.0，ip每一部分01或者00不能出现

int min(int a, int b){
    if(a<b) return a;
    return b;
}

class Solution {
	vector<string> res;
	// 检查字符串时候符合规范
	bool check(string ip) {
        // ip每部分小于3位
		if (ip.length() > 3) return false;
        // 不允许出现00，01，001这种情况
        if (ip.length()>1&&ip[0]=='0') return false;
		int temp = 0;
		for (char& c : ip) {
			temp = temp * 10 + (c - '0');
		}
		return temp >= 0 && temp <= 255;
	}
    
	// 由于深度是4，所以递归的函数需要一个深度作为参数dep
	// 剩余字符串s_rem
	// 当前为止合格的字符串pref
	void splitIP(int dep, string s_rem, string pref) {
		// 第四部分检查
		if (dep == 4) {
			if (check(s_rem))
				res.push_back(pref + "." + s_rem);
			return;
		}
		// 最多检查3位，取小值
        int len = min(3,s_rem.length());
		for (int i = 1; i <= len; i++) {
			if (check(s_rem.substr(0,i))) {
                // 给余下的部分长度必须大于0
                if(i == s_rem.length()) continue;
				if(dep == 1)
					splitIP(dep + 1, s_rem.substr(i, s_rem.length()), s_rem.substr(0, i));
				else 
					splitIP(dep + 1, s_rem.substr(i, s_rem.length()),pref+"."+ s_rem.substr(0, i));
			}
		}
		return;
	}
	
public:
	vector<string> restoreIpAddresses(string s) {
		// 特殊情况处理
		if (s.length() < 4) return res;
		string pref;
		splitIP(1, s, pref);
		return res;
	}
};
```