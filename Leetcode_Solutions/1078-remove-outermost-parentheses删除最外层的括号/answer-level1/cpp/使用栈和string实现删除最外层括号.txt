string removeOuterParentheses(string S) {
	stack<char> stack;
	string str;
	string ret;
	for (int i = 0; i < S.length();++i)
	{
		switch (S[i])
		{
		case '(':
			stack.push(S[i]);
			break;
		case ')':
			stack.pop();
			break;
		}
		if (!stack.empty())
		{
			str = str + S[i];
		}
		else
		{
			ret = ret + str.substr(1, str.length() - 1);
			str.clear();
		}
		
	}
	return ret;
}