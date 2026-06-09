```
class Solution {
public:
	int compareVersion(string version1, string version2) {
		vector<int> v_version1 = getVector(version1);
		vector<int> v_version2 = getVector(version2);
		int len = v_version1.size() < v_version2.size() ?
		          v_version1.size() : v_version2.size();
		bool flag = false;
		int res = 0;
		for (int i = 0; i < len; i++) {
			if (v_version1[i] > v_version2[i]) {
				res = 1;
				flag = true;
				break;
			} else if (v_version1[i] < v_version2[i]) {
				res = -1;
				flag = true;
				break;
			} else {
				continue;
			}
		}
		if (!flag) {
			if (len == v_version1.size()) {
				for (int i = 0; i < v_version2.size() - len; i++) {
					if (v_version2[len + i] > 0) {
						res = -1;
						break;
					}
				}
			} else {
				for (int i = 0; i < v_version1.size() - len; i++) {
					if (v_version1[len + i] > 0) {
						res = 1;
						break;
					}
				}
			}
		}

		return res;
	}

	vector<int> getVector(string version) {
		vector<int> v;
		int pos = 0, j;
		for (; pos < version.length(); ) {
			if (version[pos] != '.') {
				j = pos + 1;
				for (; j < version.length() ;j++) {
					if (version[j] == '.') break;
				}
				v.push_back(stoi(version.substr(pos, j - pos).c_str()));
				pos = j + 1;
			}
		}

		return v;
	}
};
```
