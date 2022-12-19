### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	bool buddyStrings(string A, string B) {
		if (A.size() != B.size()) return false;
		else {
			int n = A.size();
			int count = 0;
			int index1 = -1, index2 = -1;
			map<char, int> hash;
			for (int i = 0; i < n; i++) {
				if (hash.find(A[i])==hash.end()) {
					hash[A[i]] = 1;
				}
				else {
					hash[A[i]]++;
				}
				if (count==0&&A[i]!=B[i]) {
					index1 = i;
					count++;
				}
				else if (count == 1 && A[i] != B[i]) {
					index2 = i;
					count++;
				}
				else if (A[i] != B[i]) { count++; if (count >= 2) return false; }

			}
			if ((index1>=0&&index2>=0)&&A[index1] == B[index2] && A[index2] == B[index1]) return true;
			if (index1 == -1 && index2 == -1) {
				map<char, int>::iterator it;
				for (it = hash.begin(); it != hash.end(); it++) {
					if (it->second>=2) {
						return true;
					}
				}
				return false;
			}
			return false;
		}
	}
};

```