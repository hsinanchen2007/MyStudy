### 解题思路
此处撰写解题思路
![微信截图_20200211113820.png](https://pic.leetcode-cn.com/c00c16823ba44274dfee7219500652fe0bc04d144f3089c8b369f4d10af65d70-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200211113820.png)

### 代码

```cpp
class Solution {
	static const int MAPLEN = 0xff + 1;
	int smap[MAPLEN];
	int tmap[MAPLEN];
	
public:
	string minWindow(string s, string t) {
		if (t.size() <= 0 || s.size() < t.size()) return "";
		if (!init(s, t)) return "";
		auto right = rightShift(s, t);
		if (right <= t.size() - 1) return s.substr(0, t.size());
		int left = 0;
		int pos = 0;
		int miniLen = right - left + 1;
		while (0 <= left && left <= right && t.size() <= (right - left + 1) && right < s.size()) {
			//cout << s.substr(left, right - left + 1) << endl;
			auto c = s[left];
			if (smap[c] - 1 >= tmap[c]) { left++; smap[c]--; }
			else if(right < s.size()){ right++; c = s[right]; smap[c]++;}
			if ((right - left + 1) <= miniLen) { miniLen = (right - left + 1); pos = left; }
		}
		return s.substr(pos, miniLen);
	}

	int rightShift(string& s, string& t) {
		int i = s.size() - 1;
		for (; i >= t.size() - 1; i--) {
			auto c = s[i];
			if (smap[c] - 1 >= tmap[c]) { smap[c]--; }
			else { break; }
		}
		return i;
	}

	bool init(string& s, string& t) {
		size_t size = sizeof(int) * MAPLEN;
		memset(smap, 0, size);
		memset(tmap, 0, size);
		for (auto c : t) {tmap[c]++;}
		for (auto c : s) { smap[c]++; }
		for (int i = 0; i < MAPLEN; i++) { if (smap[i] < tmap[i]) {return false; }}
		return true;
	}

};
```