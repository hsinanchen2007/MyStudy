### 解题思路
利用栈的思想，通过数组实现，

### 代码

```c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

bool isValid(char * s) {
	int len = strlen(s);
	if (len == 0)
		return true;
	char* cstack = (char *)calloc(len, sizeof(char));
	int top = -1;//栈顶指针
	for (int i = 0; i < len&&s[i] != '\0'; i++) {//对s进行遍历
		if (top == -1) {//栈为空的话，s中的元素直接进栈
			top++;
			cstack[top] = s[i];
		}

		else if ((cstack[top] == '('&&s[i] == ')') || (cstack[top] == '{'&&s[i] == '}') || (cstack[top] == '['&&s[i] == ']'))//如果栈顶元素与即将进栈的元素匹配，栈顶元素出栈，栈顶指针减1
			top--;

		else {//如果不匹配，进栈
			top++;
			cstack[top] = s[i];
		}

	}
	if (top == -1)//遍历完s后，所有括号相匹配的话，栈应当为空，即top=-1
		return true;
	else
		return false;

}
```