class Solution {
public:
	bool backspaceCompare(string S, string T) {
		stack<char> sa,ta; 
		int Ssize = S.size(), Tsize = T.size();
		for (int i = 0; i < Ssize; ++i) {
			if (S[i] == '#' && !sa.empty()) sa.pop();
			else if(S[i]!='#') sa.push(S[i]);
		}
		for (int i = 0; i < Tsize; ++i) {
			if (T[i] == '#' && !ta.empty()) ta.pop();
			else if(T[i]!='#') ta.push(T[i]);
		}
		if (sa.size() != ta.size()) return false;
		while (!sa.empty()) {
			if (sa.top() != ta.top()) return false;
			sa.pop(); ta.pop();
		}
		return true;
	}
};