```
class Solution {
public:
	int uniqueMorseRepresentations(vector<string>& words) {
		set<string> s;
		vector<string> trans = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
		for (int i = 0; i < words.size(); i++){
			string tmp = "";
			for (int j = 0; j < words[i].length(); j++){
				tmp += trans[words[i][j] - 'a'];
			}
			s.insert(tmp);
		}
		return s.size();
	}
};
```
