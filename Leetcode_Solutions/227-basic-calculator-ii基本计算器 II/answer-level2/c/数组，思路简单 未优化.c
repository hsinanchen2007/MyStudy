### 解题思路
此处撰写解题思路

### 代码

```c
int calculate(char * s) {
	int stack1[100000] = { 0 };
	char stack2[100000] = { '\0' };
	int top1 = -1;
	int top2 = -1;
	int rst = 0;
	int len = strlen(s);
	int cnt = 0;
	int cnt2 = 0;
	int i, j;
	char tmp[100] = { '\0' };
	int num;
	for (i = 0; i < len; i++) {
		if (s[i] == ' ') {
			continue;
		}
		if (s[i] == '+' || s[i] == '-') {
			stack2[++top2] = s[i];
		}
		if (s[i] >= '0' && s[i] <= '9') {
			cnt = 0;
			while (s[i + cnt] >= '0' && s[i + cnt] <= '9' && cnt + i < len) {
				tmp[cnt] = s[i + cnt];
				cnt++;
			}
			num = atoi(tmp);
			stack1[++top1] = num;
			memset(tmp, 0, sizeof(tmp));
			i += cnt;
			i--;
		}
		if (s[i] == '*' || s[i] == '/') {
			cnt2 = 1;
			cnt = 0;
			while (s[i + cnt2] == ' ') {
				cnt2++;
			}
			while (s[i + cnt + cnt2] >= '0' && s[i + cnt + cnt2] <= '9' && cnt + i + cnt2< len) {
				tmp[cnt] = s[i + cnt + cnt2];
				cnt++;
			}
			num = atoi(tmp);
			if (s[i] == '*') {
				stack1[top1] *= num;
			}
			else {
				stack1[top1] /= num;
			}
			memset(tmp, 0, sizeof(tmp));
			i += cnt + cnt2;
			i--;
		}
	}
	rst = stack1[0];
	for (i = 0; i <= top1-1 && i <= top2;i++) {
		if (stack2[i] == '+') {
			rst += stack1[i+1];
		}
		else {
			rst -= stack1[i+1];
		}
	}
	return rst;
}
```