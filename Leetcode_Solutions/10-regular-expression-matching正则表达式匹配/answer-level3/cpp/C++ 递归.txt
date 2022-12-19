class Solution {
public:
	const char bk = '\0';

	bool isMatch(string s, string p) {
		s.push_back(bk);
		p.push_back(bk);
		int i = 0;
		int j = 0;
		while (i < s.size() && j < p.size()) {
			if (j + 1 < p.size() && '*' == p.at(j + 1)) {
				if (isMatch(s.substr(i, s.size() - i), p.substr(j + 2, p.size() - (j + 2)))) {
					return true;
				} else if (eq(s.at(i), p.at(j))) {
					i++; continue;
				} else {
					return false;
				}
			}
			if (eq(s.at(i), p.at(j))) { i++; j++; continue; } else { return false; }

		}

		return true;
	}

	bool eq(char s, char p) {
		return s == p || (s != bk && p == '.');
	}
};