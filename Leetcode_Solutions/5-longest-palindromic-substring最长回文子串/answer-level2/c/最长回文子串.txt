
![image.png](https://pic.leetcode-cn.com/1e32d4cb274b338ec3d1e391f88e7dc0e4204bf429055e4ef0943fac2f6b50cc-image.png)

```
int inline min(int x, int y) {
	return x > y ? y : x;
}

int inline max(int x, int y) {
	return x > y ? x : y;
}

char *longestPalindrome(char *s) {
	int dslen;
	int slen = strlen(s);
	int max_pf = 0, max_len = 1;

	if (!slen)
		return s;
	dslen = (slen << 1) - 1;

	for (int i = 2; i < dslen; i++) {
		int pl = (i - 2) / 2;
		int pr = ((i + 1) / 2);
		int flag = 0;
		do {
			if (s[pl] != s[pr]) {
				flag -= 1;
				break;
			}
			flag = 2;
		} while (--pl >= 0 && ++pr <= slen);
		if (flag >= 1) {
			if (flag == 1) {
				pl++;
				pr--;
			} else if (flag == 2) {
				pl = max(pl, 0);
				pr = min(pr, slen);
			}
			if ((pr - pl) + 1 > max_len) {
				max_pf = pl;
				max_len = pr - pl + 1;
			}
		}
	}

	s[max_pf + max_len] = '\0';
	return s + max_pf;
}
```
