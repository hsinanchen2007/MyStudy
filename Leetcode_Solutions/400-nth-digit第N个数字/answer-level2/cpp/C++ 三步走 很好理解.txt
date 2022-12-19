第一步确定位数
第二步确定数字
第三步确定数位

```cpp
class Solution {
public:
    vector<int> t{ 0,9,189,2889,38889,488889,5888889,68888889,788888889,INT_MAX };
    int findNthDigit(int n) {
	int ptr = 0;
	while (n > t[ptr])
	    ++ptr;
	int div = (n - t[ptr - 1]) / ptr;
	int mod = (n - t[ptr - 1]) % ptr;
	if (mod == 0) {
	    mod = ptr;
	    --div;
	}
	int number = pow(10, ptr - 1) + div;
	return getDigit(number, --mod);
    }

    int getDigit(int& n, int& d) {
	vector<int> vec;
	while (n) {
	    vec.push_back(n % 10);
	    n /= 10;
	}
	return vec[vec.size() - d - 1];
    }
};
```