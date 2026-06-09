利用iterator及标准库函数reverse：

```c++ []
string reverseStr(string s, int k) {
	for (string::iterator it = s.begin(); it < s.end(); it += 2 * k)
		if (it + k < s.end()) reverse(it, it + k);
		else reverse(it, s.end());
	return s;
```

其实，如果原函数改为void和&s，可以省去return，仅3行有效代码。
