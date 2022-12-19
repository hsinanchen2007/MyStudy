/* 8ms */
```
class Solution {
public:
	vector<bool> prefixesDivBy5(vector<int>& A) {
		vector<bool> result;
		int n = 0;
		for (auto & a : A) {
			n <<= 1;
			n |= a;
			if (n >= 5) {
				n -= 5;
			}
			result.push_back(n == 0);
		}
		return result;
	}
};
```
