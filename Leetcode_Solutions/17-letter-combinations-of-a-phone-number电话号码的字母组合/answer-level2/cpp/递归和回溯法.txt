### 解题思路
用递归和回溯解就可以了！

### 代码

```cpp
class Solution {
public:
   map<int, string>imap;
vector<string>svec;
void permutation(string digits,int index,string s) 
{
	int value = digits[index] - '0';
	string str = imap[value];
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (index == digits.length() - 1) 
		{
			svec.push_back(s + str[i]);
		}
		else
		   permutation(digits, index + 1, s + str[i]);
	}	
}
vector<string> letterCombinations(string digits) {	
	imap[2] = "abc";
	imap[3] = "def";
	imap[4] = "ghi";
	imap[5] = "jkl";
	imap[6] = "mno";
	imap[7] = "pqrs";
	imap[8] = "tuv";
	imap[9] = "wxyz";

	permutation(digits,0,"");
	return svec;
}


};
```