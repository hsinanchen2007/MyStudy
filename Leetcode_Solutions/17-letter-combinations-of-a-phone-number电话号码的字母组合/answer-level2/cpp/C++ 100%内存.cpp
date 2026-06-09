```
class Solution {
public:
	/*
	** vector<string> last, cur;
	*/
	string getChars(char c)
	{
		if(c == '2') return "abc";
		if(c == '3') return "def";
		if(c == '4') return "ghi";
		if(c == '5') return "jkl";
		if(c == '6') return "mno";
		if(c == '7') return "pqrs";
		if(c == '8') return "tuv";
		if(c == '9') return "wxyz";
		return "";
	}
    vector<string> letterCombinations(string digits) {
        vector<string> last, cur;
		if(digits.empty()) return cur;
        
		last.push_back("");
		for(int i = 0; i < digits.size();i++)
		{
			cur.clear();
			string chars = getChars(digits[i]);
			for(int j = 0; j < last.size();j++)
			{
				for(int k = 0; k < chars.size();k++)
				{
					cur.push_back(last[j] + chars[k]);
				}
			}
			last = cur;
		}
		return last;
    }
};
```
