### 解题思路
现在用C语言刷题的答案好少，很挫的思路；用一个栈，遇到左括号入栈，右括号出栈
考虑到情况：
1.有空格必false
2.结束后栈必须是空的，否则false
3.只有左括号入栈，如果栈空入栈的第一个必须是左括号，是右括号就false


### 代码

```c
bool isPair(char a, char b) {
    if ((a == '(' && b == ')') || (a=='{' && b == '}') || (a == '[' && b == ']')) {
        return true;
    }else {
        return false;
    }
}

bool isValid(char * s){
	int length = strlen(s);
	char *stack = (char *)malloc(sizeof(char) * length);
	int top = 0;

	int k = 0;
	while (s[k] != '\0') {
		if (s[k] == ' ') {
			return false;
		}
		if (top == 0) {
			if (s[k] == '}' || s[k] == ')' || s[k] == ']') {
				return false;
			}
			stack[top++] = s[k++];
		} else if (s[k] == '(' || s[k] == '{' || s[k] == '[') {
			stack[top++] = s[k++];
		} else {
			if (isPair(stack[top - 1], s[k])) {
				k++;
				top--;
				continue;
			} else {
				return false;
			}
		}

	}

	if (top != 0) {
		return false;
	}
	return true;
}
```