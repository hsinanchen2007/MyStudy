```C++ []
class Solution {
public:
	int hammingDistance(int x, int y) {
		int count = 0, n = x ^ y;
		while (n) {
			if (n & 1) {
				count++;
			}
			n >>= 1;
		}
		return count;
	}
};
```
