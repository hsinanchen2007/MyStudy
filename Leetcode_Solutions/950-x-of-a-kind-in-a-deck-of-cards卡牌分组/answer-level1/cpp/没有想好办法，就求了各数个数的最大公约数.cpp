如题

**代码**
```C++ []
class Solution {
public:
	int gcd(int x, int y)
	{
		if (!x)
			return y;
		if (!y)
			return x;
		int z = y;
		while (x % y != 0)
		{
			z = x % y;
			x = y;
			y = z;
		}
		return z;
	}

	bool hasGroupsSizeX(vector<int>& deck) {
		unordered_map<int, int> m;
		for (int data : deck)
			m[data]++;
		int g = 0;
		for (auto it : m) {
			g = gcd(g, it.second);
			if (g < 2)
				return false;
		}
		if (g > 1)
			return true;
		return false;
	}
};
```
