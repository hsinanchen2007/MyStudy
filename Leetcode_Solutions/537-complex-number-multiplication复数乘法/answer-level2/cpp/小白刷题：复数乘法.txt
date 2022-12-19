复数乘法大家都会算，因此本题思路就是把两复数字符串实部和虚部分离出来，计算完毕构造答案字符串

能不用库函数尽量不用，减少意外bug&节省时间

代码：
```
class Solution {
public:
	string complexNumberMultiply(string a, string b) {
		int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
		int i1 = 0, i2 = 0;
		bool neg = false;
		if (a[i1] == '-') {
			i1++;
			neg = true;
		}
		for (; a[i1] != '+'; i1++)
			a1 = a1 * 10 + (a[i1] - '0');
		a1 = neg ? (-a1) : a1;
		i1++;
		neg = false;
		if (a[i1] == '-') {
			i1++;
			neg = true;
		}
		for (; a[i1] != 'i'; i1++)
			a2 = a2 * 10 + (a[i1] - '0');
		a2 = neg ? (-a2) : a2;
		neg = false;
		if (b[i2] == '-') {
			i2++;
			neg = true;
		}
		for (; b[i2] != '+'; i2++)
			b1 = b1 * 10 + (b[i2] - '0');
		b1 = neg ? (-b1) : b1;
		i2++;
		neg = false;
		if (b[i2] == '-') {
			i2++;
			neg = true;
		}
		for (; b[i2] != 'i'; i2++)
			b2 = b2 * 10 + (b[i2] - '0');
		b2 = neg ? (-b2) : b2;
		int real = a1 * b1 - a2 * b2;
		int img = a1 * b2 + a2 * b1;
		string ans = "";
		if (real < 0) {
			ans += "-";
			real = -real;
		}
		if (!real)
			ans += "0";
		else {
			string r = "";
			while (real) {
				r.insert(0, 1, '0' + real % 10);
				real /= 10;
			}
			ans += r;
		}
		ans += "+";
		if (img < 0) {
			ans += "-";
			img = -img;
		}
		if (!img)
			ans += "0";
		else {
			string im = "";
			while (img) {
				im.insert(0, 1, '0' + img % 10);
				img /= 10;
			}
			ans += im;
		}
		ans += "i";
		return ans;
	}
};
```
