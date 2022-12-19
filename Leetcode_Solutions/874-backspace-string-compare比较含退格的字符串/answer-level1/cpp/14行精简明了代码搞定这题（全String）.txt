class Solution {
public:
	bool backspaceCompare(string S, string T) {
		string s1, t1;
		for (char it : S) {
			if (it == '#'&& !s1.empty())
				s1.pop_back();
			else if (it != '#')
				s1.push_back(it);
		}
		for (char it : T) {
			if (it == '#' &&!t1.empty())
				t1.pop_back();
			else if (it != '#')
				t1.push_back(it);
		}
		return s1 == t1;
	}
};