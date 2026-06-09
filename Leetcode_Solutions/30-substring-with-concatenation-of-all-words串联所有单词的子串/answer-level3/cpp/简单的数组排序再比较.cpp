### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
		if (s.size() <= 0 || words.size() <= 0 || words.begin()->size() <= 0)
			return result;
		int wlen = words.begin()->size();
		int wcot = words.size();
		if (wlen * wcot > s.size()) return result;
		sort(words.begin(), words.end());
		vector<string> buff;
		for (int i = 0; i <= s.size() - (wlen*wcot); i++) {
			stepSplit(&s, i, wlen, wcot, &buff);
			sort(buff.begin(), buff.end());
			if (buff == words) result.push_back(i);
			buff.clear();
		}
		return result;

	}
	void stepSplit(string *s, int i,int k,int n,vector<string> *result) {
		while(n--){
			result->push_back(s->substr(i, k));
			i += k;
		}
	}

};
```