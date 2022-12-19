![image.png](https://pic.leetcode-cn.com/69a674e6d44d9577c52959d0ab79d4e0725d98b775aa135f4a9b9fe8f461f534-image.png)


```
char *convert(char *s, int numRows) {
	if (numRows <= 1)
		return s;

	int slen = strlen(s) - 1;
	int pres = 0;
	char *res = malloc(sizeof(char) * (slen + 2));
	int mtop = 2 * numRows - 2;
	int cycle = slen / mtop;
	int l, r, top;

	for (int i = 0; i < numRows; i++) {
		for (int n = 0; n <= cycle; n++) {
			top = n * mtop;
			l = top - i;
			r = top + i;
			if (i != numRows - 1 && l >= 0)
				res[pres++] = s[l];
			if (l != r && r <= slen)
				res[pres++] = s[r];
		}
		if ((top += mtop - i) <= slen && i != numRows - 1)
			res[pres++] = s[top];
	}

	res[pres] = '\0';
	return res;
}
```
