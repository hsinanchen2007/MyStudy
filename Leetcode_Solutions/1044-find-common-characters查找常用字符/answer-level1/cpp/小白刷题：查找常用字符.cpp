创建一长度为26的整形数组来存储单词中字母频度，每次遍历一个字符串并更新频度最小值，最后根据频度得出结果

顺便，能预设字符串最好不要构造，费时间……

代码：
```
class Solution {
public:
	vector<string> commonChars(vector<string>& A) {
		vector<string> ans;
		int num = A.size();
		int count[26];
        
        string use[26] = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z" };
		
		for (int i = 0; i < 26; i++)
			count[i] = 101;
		for (int i = 0; i < num; i++) {
			int word[26] = { 0 };
			int len = A[i].length();
			for (int j = 0; j < len; j++)
				word[(int)A[i][j] - 97]++;
			for (int j = 0; j < 26; j++)
				if (count[j]) {
					count[j] = count[j] < word[j] ? count[j] : word[j];
				}
		}
		for (int i = 0; i < 26; i++) {
			if (count[i]) {
				for (int j = 0; j < count[i]; j++) {
					string s(1, (char)(i + 97));
					ans.push_back(s);
				}
			}
		}
		return ans;
	}
};
```
