### 解题思路
此处撰写解题思路

### 代码

```c
int SetEqualInFlag(char *flag, char a, char b, int cnt)
{
	int i;
	int temp;
	printf("1 a: %c 1 b: %c fa %d fb %d \n", a, b, flag[a - 'a'], flag[b - 'a']);
	if (flag[a - 'a'] < 0 && flag[b - 'a'] < 0) {
		flag[a - 'a'] = cnt;
		flag[b - 'a'] = cnt;
	}

	if (flag[a - 'a'] < 0 && flag[b - 'a'] > 0) {
		flag[a - 'a'] = flag[b - 'a'];
	}

	if (flag[a - 'a'] > 0 && flag[b - 'a'] < 0) {
		flag[b - 'a'] = flag[a - 'a'];
	}

	if (flag[a - 'a'] > 0 && flag[b - 'a'] > 0) {
		temp = flag[a - 'a'];
		for (i = 0; i < 26; i++) {
			if (flag[i] == temp) {
				flag[i] = flag[b - 'a'];
			}
		}
	}
	printf("2 a: %c 2 b: %c fa %d fb %d \n", a, b, flag[a - 'a'], flag[b - 'a']);

	return 1;
}

bool equationsPossible(char ** equations, int equationsSize){
	int i;
	char *flag = (char *)malloc(26 * sizeof(char));
	for (i = 0; i < 26; i++) {
		flag[i] = -1 - i;
	}

	int cnt = 1;
	int ret;
	for (i = 0; i < equationsSize; i++) {
		if (equations[i][1] == '=') {
			SetEqualInFlag(flag, equations[i][0], equations[i][3], cnt);
		}
		cnt++;
	}

	char a;
	char b;
	for (i = 0; i < equationsSize; i++) {
		if (equations[i][1] == '!') {
			a = equations[i][0];
			b = equations[i][3];
			if (a == b) {
				return false;
			}
			printf("flag a %d \n", flag[a - 'a']);
			printf("flag b %d \n", flag[b - 'a']);
			if (flag[a - 'a'] == flag[b - 'a']) {
				
				return false;
			}
		}
	}
	
	return true;
}
```