

```
class Solution {
public:
	string simplifyPath(string path) {
		string res;
		deque<string> de;
		string str;
		int dot = 0;
		for (auto c : path) {
			if (c == '/') {
				if (dot > 0) {
					if (dot == 1) {}
					else if (dot == 2) {
						if (de.size() > 0)
							de.pop_back();
					}
					else {
						de.push_back(str);
					}
					str.clear();
				}
				else if (str.size() > 0) {
					de.push_back(str);
					str.clear();
				}
                dot = 0;
			}
			else if (c == '.') {
                if (dot != -1)
				    ++dot;
				str += c;
			}
			else {
				str += c;
                dot = -1;
			}
		}
		
		if (dot == 1) {}
		else if (dot > 1) {
			if (dot == 2) {
				if (de.size() > 0)
					de.pop_back();
			}
			else {
				de.push_back(str);
			}
		}
		else if (str.size() > 0) {
			de.push_back(str);
		}

		if (de.size() > 0) {
			while (de.size() > 0) {
				res += "/";
				res += de.front();
				de.pop_front();
			}
		}
		else {
			res += '/';
		}
		return res;
	}
};
```

