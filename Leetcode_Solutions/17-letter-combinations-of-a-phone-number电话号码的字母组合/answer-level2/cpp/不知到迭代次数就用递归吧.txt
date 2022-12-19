"23",2对应abc,3对应def;
最简单的思路双层嵌套循环，但是不知道最终输入会有几层循环，所以使用递归，设递归基，到底自动返回；
用pos标志当前处于递归调用链的哪一层，找到对应的字符，循环尝试，并深入递归下去；
```
void backtrace(string digits, vector<string>& res,map<char,string> &Hash,string &path,int pos)
{
	if (pos == digits.size()) {
		res.push_back(path);
		return;
	}
	string str = Hash[digits[pos]];
	for (char c : str) {
		path.push_back(c);
		backtrace(digits, res, Hash, path, pos + 1);
		path.pop_back();
	}
}
vector<string> letterCombinations(string digits) 
{
	vector<string> res;
	map<char, string> Hash;
	Hash['2'] = "abc", Hash['3'] = "def", Hash['4'] = "ghi", Hash['5'] = "jkl";
	Hash['6'] = "mno", Hash['7'] = "pqrs", Hash['8'] = "tuv", Hash['9'] = "wxyz";
	string path = "";
	backtrace(digits, res, Hash, path, 0);
	return res;
}
```
