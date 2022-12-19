两个都是100%
代码简单明了
```
    bool isValid(string s) {
        if (s.empty()) return true;
		stack<char>	stc;
		for (char c : s)
			if (c == ')' || c == ']' || c == '}') 
				if (!stc.empty() && stc.top() == c)
					stc.pop();
				else return false;
			else
				switch (c) {
				case '(':
					stc.push(')');
					break;
				case '[':
					stc.push(']');
					break;
				case '{':
					stc.push('}');
					break;
				}
		return stc.empty();
    }
```