### 解题思路
思路：利用空格分隔单词然后逐个处理即可

### 代码

```cpp
class Solution {
public:
	string result;
	// 判断是否是元音字符 
	bool isYAlpha(char c) {
		c = tolower(c);
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	} 
	vector<string > splitStr(string S) {
		S += ' ';
		int sLen = S.size();
		string temp, tempIndex;
		string resultTemp;
		vector<string > result;
		// 分离字符并对字符进行处理 
		for (int i = 0; i <= sLen; i++) {
			if (S[i] != ' ') {
				temp += S[i];
			} else {
				// 不管是哪种字符后面加的a都要增加 
				tempIndex += "a";
				// 元音字符 
				if (isYAlpha(temp[0])) {
					resultTemp += temp + "ma";
				} else {
					// 非元音字符 
					resultTemp += temp.substr(1, temp.size() - 1);
					// 坑：直接加temp[0]会运行错误，temp[0]不是字符串，不能直接运算 
					resultTemp += temp.substr(0, 1) + "ma";
				}
				// 添加a后缀 
				resultTemp += tempIndex;
				result.push_back(resultTemp);
				
				resultTemp.clear(); 
				temp.clear();
			}
		}
		return result;
	}
    string toGoatLatin(string S) {
        if (S.size() <= 0) return S;
        string result;
        vector<string > t = splitStr(S); 
        for (int i = 0; i < t.size(); i++) {
        	result += t[i];
        	if (i != t.size() - 1) result += ' ';
		}
		return result;
    }
};
```