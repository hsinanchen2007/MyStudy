### 解题思路
左右双指针

![image.png](https://pic.leetcode-cn.com/7004fff28e7765fd63eb67fd78620f6e8b6fdedb14573a9957dff9946278b547-image.png)


### 代码

```c
char * reverseOnlyLetters(char * S){
	int r, l;
	char tmp;
	r = 0;
	l = strlen(S) - 1;
	while (r < l) {
		if (isalpha(S[r]) == 0) {
			r++;
			continue;
		}
		if (isalpha(S[l]) == 0) {
			l--;
			continue;
		}
		tmp = S[r];
		S[r] = S[l];
		S[l] = tmp;
		r++;
		l--;
	}
	return S;
}
```