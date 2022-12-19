### 解题思路
此处撰写解题思路

### 代码

```c
bool backspaceCompare(char * S, char * T){
	int l1 = strlen(S), l2 = strlen(T), x = 0, y = 0, back = 0;
	char *a = (char*)calloc(200, sizeof(char)), *b = (char*)calloc(200, sizeof(char));
	for (int i = l1 - 1; i >= 0; i--)
		if ('#' == S[i])
			back++;
		else{
			if (back)
				back--;
			else
				a[x++] = S[i];
		}
	back = 0;
	for (int i = l2 - 1; i >= 0; i--)
		if ('#' == T[i])
			back++;
		else{
			if (back)
				back--;
			else
				b[y++] = T[i];
		}
	return strcmp(a, b) == 0;
}
```