### 解题思路
括号解析问题一般都使用栈的数据结构，此题需要注意的是存在括号嵌套的情况，所以不能一开始就跟新结果，而是需要先将栈里面的数字和括号都干掉，只留下字符串，然后在进行结果保存。


### 代码

```cpp
class Solution {
public:
string GetTransResults(string repStr, string numStr)
{
	int num = stoi(numStr);   //C++ 11可以直接stoi    int 转str : string a = to_string(XXX)
	string retStr("");
	for (int i = 0; i < num; i++) {
		retStr += repStr;
	}
	return retStr;
}

string decodeString(string s) {
	string results("");
	stack<char> strStack;
	for (int i = 0; i < s.size(); i++) {
		strStack.push(s[i]);
		if (strStack.top() == ']') {
			strStack.pop();
			string tempStr("");
			while(! strStack.empty() && strStack.top() != '[') {
				tempStr.insert(0, 1, strStack.top());
				strStack.pop();
			}
			strStack.pop();
			string numStr("");
			while(! strStack.empty() && strStack.top() >= '0' && strStack.top() <= '9') {
				numStr.insert(0, 1, strStack.top());
				strStack.pop();
			}
			string retStr = GetTransResults(tempStr, numStr);
			for (int j = 0; j < retStr.size(); j++) {
				strStack.push(retStr[j]);
			}
		}
		
	}
	while(! strStack.empty()) {
		results.insert(0, 1, strStack.top());   //插入char需要制定index和长度
		strStack.pop();
	}
	return results;
}
};
```