### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int l1 = a.size(), l2 = b.size();
	int p1 = 0, p2 = 0;
	int a1 = 0, b1 = 0, a2 = 0, b2 = 0;
	for (int i = 0; i < l1; i++) {
		if (a[i] == '+') {
			p1 = i;//加号位置
		}
		if (a[i] == 'i') {
			p2 = i;//最后的位置
		}
	}
	int sum = 0; int sig = 1;
	for (int i = 0; i < p1; i++) {
		if (i == 0 && a[i] == '-') {
			sig = -1; continue;
		}
		sum = sum * 10 + a[i] - '0';
	}
	a1 = sum * sig;
	sum = 0; sig = 1;
	for (int i = p1 + 1; i < p2; i++) {
		if (a[i] == '-') {
			sig = -1; continue;
		}
		sum = sum * 10 + a[i] - '0';
	}
	b1 = sum * sig;
	sum = 0; sig = 1;
	for (int i = 0; i < l2; i++) {
		if (b[i] == '+') {
			p1 = i;//加号位置
		}
		if (b[i] == 'i') {
			p2 = i;//最后的位置
		}
	}
	sum = 0; sig = 1;
	for (int i = 0; i < p1; i++) {
		if (i == 0 && b[i] == '-') {
			sig = -1; continue;
		}
		sum = sum * 10 + b[i] - '0';
	}
	a2 = sum * sig;
	sum = 0; sig = 1;
	for (int i = p1 + 1; i < p2; i++) {
		if (b[i] == '-') {
			sig = -1; continue;
		}
		sum = sum * 10 + b[i] - '0';
	}
	b2 = sum * sig;
	int t = 0;
	//cout << a1 << " " << b1 << " " << a2 << " " << b2 << endl;
	int x = a1 * a2 - b1 * b2;
	int y = a1 * b2 + a2 * b1;
	char f[6], s[6],r[20];
	memset(f, 0, sizeof(f));
	memset(s, 0, sizeof(s));
	memset(r, 0, sizeof(r));
	int num1 = 0,num2=0;
	if (x > 0) {
		while (x != 0) {
			f[num1++] = x % 10+'0';
			x /= 10;
		}
		for (int i = num1-1; i >=0; i--) {
			r[t++] = f[i];
		}
	}
	else if (x == 0) {
		r[t++] = '0';
	}
	else {
		r[t++] = '-';
		x = -x;
		while (x != 0) {
			f[num1++] = x % 10 + '0';
			x /= 10;
		}
		for (int i = num1 - 1; i >= 0; i--) {
			r[t++] = f[i];
		}
	}
	r[t++] = '+';
	if (y > 0) {
		while (y != 0) {
			s[num2++] = y % 10 + '0';
			y /= 10;
		}
		for (int i = num2 - 1; i >= 0; i--) {
			r[t++] = s[i];
		}
	}
	else if (y == 0) {
		r[t++] = '0';
	}
	else {
		r[t++] = '-';
		y = -y;
		while (y != 0) {
			s[num2++] = y % 10 + '0';
			y /= 10;
		}
		for (int i = num2 - 1; i >= 0; i--) {
			r[t++] = s[i];
		}

	}
	r[t++] = 'i';
	r[t++] = 0;
	return r;
    }
};
```