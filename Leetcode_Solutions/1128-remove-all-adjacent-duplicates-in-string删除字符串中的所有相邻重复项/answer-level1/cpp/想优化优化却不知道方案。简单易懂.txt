class Solution {
public:
	string removeDuplicates(string S) {

		int i = 0;
		string temp;
		while (S[i] != '\0')
		{
			a.push(S[i]);
			i++;
			while (a.top() == S[i])
			{
				a.pop();
				i++;
				if (a.empty())
					break;
			}
			
			

		}
		stack<char> a_1;
		while (!a.empty())
		{
			a_1.push(a.top());
			a.pop();
		}
		while (!a_1.empty())
		{
		temp.push_back(a_1.top());
		a_1.pop();
		}
		
		
		return temp;
	}
private:
	stack<char> a;
};