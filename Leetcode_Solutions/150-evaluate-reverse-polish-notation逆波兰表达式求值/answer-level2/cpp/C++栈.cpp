```
class Solution {
public:
	bool yunsuan(string s)
	{
		if (s == "+" || s == "-" || s == "*" || s == "/")
			return true;
		return false;
	}
	int evalRPN(vector<string>& tokens) {
		int a;
		int b;
		stack<int>s;
		for (auto iter = tokens.begin(); iter != tokens.end(); iter++)
		{
			if (!yunsuan(*iter))
			{
				s.push(stoi(*iter));
			}
			else
			{
				a = s.top();
				s.pop();
				b = s.top();
				s.pop();
				if      (*iter == "+")
					s.push(b + a);
				else if (*iter == "-")
					s.push(b - a);
				else if (*iter == "*")
					s.push(b * a);
				else if (*iter == "/")
					s.push(b / a);
			}
		}
		return s.top();
	}
};
```
