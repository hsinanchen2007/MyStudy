本来想的是malloc一个有n个元素的数组一个一个算上去，无奈水平太菜一用malloc就会出现AddressSanitizer的错误也不知道咋办。后来一想每次计算f(n)只需要把f(n-1)和f(n-2)加起来就好了，那搞一个三个元素的数组不就行了吗，于是如此……
int fib(int n) {
	int i = 0, res;
	int tmp[3] = { 0,1 };
	for (i = 2; i <= n; i++)
		tmp[i % 3] = tmp[(i - 1) % 3] + tmp[(i - 2) % 3];
	res = tmp[(n ) % 3];
	return res;
}
这样一来不仅不会遇到不知所以的addresssanitize错误还节省了空间，岂不美哉