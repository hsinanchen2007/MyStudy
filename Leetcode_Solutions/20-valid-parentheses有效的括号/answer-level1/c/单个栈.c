### 解题思路
此处撰写解题思路

### 代码

```c
bool isValid(char* s) {
	int len = strlen(s);
	if (len == 0) return true;
	if (len & 1) return false;
	int ret = true;
	char* stack = (char*)malloc(sizeof(char) * len);
	int top = -1;
	for (int i = 0; i < len; i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			stack[++top] = s[i];
		}
		else {
			if (top == -1) return false;
			if (s[i] == stack[top] + 1 || s[i] == stack[top]+2) {
				top--;
			}
			else {
				return false;
			}
		}
	}
	free(stack);
	return top == -1;
}
```