```C++ []
class Solution {
public:
	vector<string> letterCasePermutation(string S) {
		vector<string> res = { "" };
		for (int i = 0; i < S.length(); i++) {
			vector<string> tmp;
			for (int j = 0; j < res.size(); j++) {
				if (S[i] >= 'a' && S[i] <= 'z') {
					tmp.push_back(res[j]+string(1, S[i] - 'a' + 'A'));
				}
				else if (S[i] >= 'A' && S[i] <= 'Z') {
					tmp.push_back(res[j]+string(1, S[i] - 'A' + 'a'));
				}
				tmp.push_back(res[j]+string(1, S[i]));
			}
			res = tmp;
		}
		return res;
	}
};
```
