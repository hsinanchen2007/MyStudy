## 循环遍历每个单词，判断该单词的所有字母是否都在Line里面
```
class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		vector<string>res;
		string Line1 = "qwertyuiopQWERTYUIOP";
		string Line2 = "asdfghjklASDFGHJKL";
		string Line3 = "zxcvbnmZXCVBNM";
		for (int i = 0; i < words.size(); i++) {
			if (Line1.find(words[i][0]) <= Line1.size()) {
				int cnt = 0;
				for (int j = 0; j < words[i].size(); j++) {
					if (Line1.find(words[i][j]) <= Line1.size()) {
						cnt++;
					}
					else {
						break;
					}
					if (cnt == words[i].size()) {
						res.push_back(words[i]);
					}
				}
			}else
				if (Line2.find(words[i][0]) <= Line2.size()) {
					int cnt = 0;
					for (int j = 0; j < words[i].size(); j++) {
						if (Line2.find(words[i][j]) <= Line2.size()) {
							cnt++;
						}
						else {
							break;
						}
						if (cnt == words[i].size()) {
							res.push_back(words[i]);
						}
					}
			}else
				if (Line3.find(words[i][0]) <= Line3.size()) {
					int cnt = 0;
					for (int j = 0; j < words[i].size(); j++) {
						if (Line3.find(words[i][j]) <= Line3.size()) {
							cnt++;
						}
						else {
							break;
						}
						if (cnt == words[i].size()) {
							res.push_back(words[i]);
						}
					}
				}
		}
		return res;
	}
};
```
