不过必须假设int的值 int 范围内的正整数
```
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
	if (x == 1) return 1;

	int r= 46340;
	int l = 0;

	while (r >= l)
	{
		int mid = l + (r - l) / 2;
		if (x == mid* mid)
			return mid;
		if (x < mid * mid)
			r = mid - 1;
		if (x > mid* mid)
			l = mid + 1;
	}
	return r;
    }
};
```
