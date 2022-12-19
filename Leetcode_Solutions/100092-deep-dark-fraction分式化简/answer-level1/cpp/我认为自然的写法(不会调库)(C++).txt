1. 直接看代码就好,欢迎指点批评,小白正在学习
```
class Solution {
public:
	int maxvsolve(int n, int m) {
		int minv = min(n, m);
		int maxv = -1;
		for (int i = 2; i <=minv;i++) {
			if (n%i == 0 && m%i == 0) {
				maxv = max(maxv, i);
			}
		}
		return maxv;
	}
	vector<int> fraction(vector<int>& cont) {
		int len = cont.size();
		vector<int> res(2);
		if (len == 0)
			return res;
		if (len == 1) {
			res[0] = cont[len - 1];
			res[1] = 1;
			return res;
		}
		int n = cont[len - 2]*cont[len-1] + 1, m = cont[len - 1];
		for (int i = 1; i <= len-2; i++) {
			int tmp = n;
			n = m + cont[len - (i+2)]*n;
			m = tmp;
		}
		int maxv = maxvsolve(n, m);
		if (maxv != -1) {
			n = n / maxv;
			m = m / maxv;
		}
		res[0] = n; 
		res[1] = m;
		return res;
	}
};

```

