1、使用一个和字符串长度相等的数组来存储该位置字符是否有效,0：有效，1无效；
2、使用栈来匹配括号，无效括号处置为1；
3、遍历完之后要检查栈中是否剩余括号，剩余的都为无效括号
```
string minRemoveToMakeValid(string s) {
	string res = "";

	stack<int> stk;
	int size = s.size();
	vector<int> sarr(size, 0);
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == ')') {
			stk.push(i);
		}
		else if (s[i] == '(') {
			//查看左括号是否有匹配的右括号
			if (!stk.empty()) {
				stk.pop();
			}
			else {
				//无效括号处置1
				sarr[i] = 1;
			}
		}
	}
	//栈中剩余的括号都为无效括号
	while (!stk.empty()) {
		sarr[stk.top()] = 1;
		stk.pop();
	}

	for (int i = 0; i < size; i++) {
		if (sarr[i] == 0) {
			res += s[i];
		}
	}
	return res;
}
```
