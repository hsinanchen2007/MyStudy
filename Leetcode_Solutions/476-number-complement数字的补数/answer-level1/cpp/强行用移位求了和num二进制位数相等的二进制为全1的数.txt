这是个辣鸡方法
```
class Solution {
public:
	int findComplement(int num) {
		int tmp = num, res = 0;
		while (tmp) {
			tmp >>= 1;
			res = (res << 1) + 1;
		}
		res = res - num;
		return res;
	}
};
```
