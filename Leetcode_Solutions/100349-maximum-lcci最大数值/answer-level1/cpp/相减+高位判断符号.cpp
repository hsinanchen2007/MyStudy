```
class Solution {
public:
	int maximum(int a, int b) {
		long long m = (long long)a - (long long)b;
		int ret[2] = { a,b };
		return ret[(((unsigned long long)m) >> 63) & 1];
	}
};
```
