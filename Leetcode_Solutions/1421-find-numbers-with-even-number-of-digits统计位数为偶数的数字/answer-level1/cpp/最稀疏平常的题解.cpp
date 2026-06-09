```C++ []
class Solution {
public:
	int findNumbers(vector<int>& nums) {
		int res = 0;
		for (int num : nums) {
			if (!num)
				continue;
			int cnt = 0;
			while (num) {
				cnt++;
				num /= 10;
			}
			if (~cnt & 1) {
				res++;
			}
		}
		return res;
	}
};
```
