### 解题思路
使用整数的地板除法巧妙的减少了判断

### 代码

```c
int longestPalindrome(char * s) {
	int count[2][26] = { 0 };
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if ('a' <= s[i] &&s[i]<= 'z') {
			count[0][s[i] - 97] ++;
		}else{
			count[1][s[i] - 65]++;
		}
	}
	int ret = 0;
	for (int i = 0; i < 26; i++) {
		ret += count[0][i] / 2 * 2;
		ret += count[1][i] / 2 * 2;
		if((count[0][i]%2==1||count[1][i]%2==1)&&ret%2==0){
			ret ++;
		}
	}
	return ret;
}
```