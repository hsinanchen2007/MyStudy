```
class Solution {
public:
	bool isHappy(int n) {
		while (n != 1 && n != 4)
		{
			int res = 0;
			while (n > 0)
			{
				res += (n % 10)*(n % 10);
				n = n / 10;
			}
			n = res;
		}
		if (n == 1)
			return true;
		return false;
	}
};
```
