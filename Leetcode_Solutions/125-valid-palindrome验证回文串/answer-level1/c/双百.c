解题思路：先把字符串整理一下，再对照两端是否一致。
```
bool isPalindrome(char * s){
	int i, j, len = strlen(s);
	for (i = j = 0; j < len; j++) {
		if (s[j] >= 'A'&&s[j] <= 'Z') {
			s[i++] = s[j] + 32;
		}
		else if (s[j] >= 'a'&&s[j] <= 'z' || s[j] >= '0'&&s[j] <= '9') {
			s[i++] = s[j];
		}
	}
	len = i;
	for (i = 0, j = len - 1; i < j; i++, j--) {
		if (s[i] != s[j])return false;
	}
	return true;
}
```

