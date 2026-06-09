分治算法是将一个大的问题分解到若干个小问题，将小问题的答案进行组合得到原问题的答案。
我采用的是递归函数来实现分治
在此之前，我们需要对两个大数做一些数学处理
对于两个相同位数的大数A,B，且位数为2的整数次方，我们可以吧每个数按位数从中间分成两个数的和，如下图：
![854705-82a5232bb3ff2a5f.png](https://pic.leetcode-cn.com/a985db6c5601f8b94e4c1d3e8e05da3850bc087af5ff4f705c1a7dd777e53b14-854705-82a5232bb3ff2a5f.png)
将A分成a1和a0
将B分成b1和b0
```
A = a1 * 10^(n/2) + a0
B = b1 * 10^(n/2) + b0
A * B = c2 * 10^n + c1 * 10^(n/2) + c0
其中：
c2 = a1 * b1
c1 = a0 * b1 + b0 * a1 = (a1 + a0) * (b1 + b0) - (c2 + c0)
(尽量减少乘法运算，需要将c1变形成后面的式子)
```
如此就将一个n位大数乘法转化成了3个n/2位的大数乘法和若干大数加法以及移位算法（在10进制中只需要往尾部补零）
根据分治主定理
![1148798-20170930091321059-2034070758.png](https://pic.leetcode-cn.com/e39c1f5d65d12051c14080919afe1a77cb1fb59bfead895027aea3a5a1c7a597-1148798-20170930091321059-2034070758.png)，这个式子的
时间复杂度为
![1148798-20170930091334137-2036474507.png](https://pic.leetcode-cn.com/b5d44c10edc4f3cd7fd134db3017fd33a3bad0f8982816996a31d957bcee9918-1148798-20170930091334137-2036474507.png)

下面给出大数乘法的主体框架，其中需要用到大数加法和大数减法的各种模块，并未在代码中实现。
```
string multiply(string num1, string num2) {
	int init_len = 4;
	if (num1.length() > 2 || num2.length() > 2) {
		int max_len = max(num1.length(), num2.length());
		while (init_len < max_len)	init_len *= 2;
		add_pre_zero(num1, init_len - num1.length());
		add_pre_zero(num2, init_len - num2.length());
	}
	if (num1.length() == 1) {
		add_pre_zero(num1, 1);
	}
	if (num2.length() == 1) {
		add_pre_zero(num2, 1);
	}
	int n = num1.length();

	string result;

	string a1, a0, b1, b0;
	if (n > 1) {
		a1 = num1.substr(0, n / 2);
		a0 = num1.substr(n / 2, n);
		b1 = num2.substr(0, n / 2);
		b0 = num2.substr(n / 2, n);
	}
	if (n == 2) {
		int x1 = atoi(a1.c_str());
		int x2 = atoi(a0.c_str());
		int y1 = atoi(b1.c_str());
		int y2 = atoi(b0.c_str());
		int z = (x1 * 10 + x2) * (y1 * 10 + y2);
		result = to_string(z);
	}
	else {
		string c2 = multiply(a1, b1);
		string c0 = multiply(a0, b0);
		string temp_c1_1 = add(a0, a1);
		string temp_c1_2 = add(b1, b0);
		string temp_c1_3 = add(c2, c0);	
		string temp_c1 = multiply(temp_c1_1, temp_c1_2);
		string c1 = subtract(temp_c1, temp_c1_3);
		string s1 = add_last_zero(c1, n / 2);
		string s2 = add_last_zero(c2, n);
		result = add(add(s1, s2), c0);
	}
	return result;
}
```
详情参考链接：https://www.jianshu.com/p/b5af56d676b2
