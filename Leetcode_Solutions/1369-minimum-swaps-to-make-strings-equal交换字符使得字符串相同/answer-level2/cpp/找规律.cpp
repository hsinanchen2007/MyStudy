通过交换可以变相同的只有两种情况：
1、'xx'，'yy'只需一次交换即可相同；
2、'xy'，'yx'需交换二次；
```
int minimumSwap(string s1, string s2) {
	if (s1.size() != s2.size()) return 0;

	int res = 0;
	int diff1 = 0, diff2 = 0;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] != s2[i]) {
			if (s1[i] == 'x') {
				diff1++;
				if (diff1 == 2) {
					res++;
					diff1 = 0;
				}
			}
			else {
				diff2++;
				if (diff2 == 2) {
					res++;
					diff2 = 0;
				}
			}
		}
	}
	if (diff1 == 1 && diff2 == 1) {
		res += 2;
	}
	else if (diff1 != 0 || diff2 != 0) {
		return -1;
	}
	return res;
}
```
