### 解题思路
添加进来的index从小到大，所以查找的时候不用全遍历

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *minRemoveToMakeValid(char *s)
{
	int i = 0;
	int total = 0;
	int index = 0;
	int ans_size = 0;
	int *stack;
	int stack_size = 0;
	char *ans;

	if (!s || strlen(s) == 0) {
		return NULL;
	}
	total = strlen(s) + 1;
	ans = (char *)malloc(total);
	stack = (int *)malloc(total * sizeof(int));
	//memset(ans, 0, total);
	ans_size = 0;
	for (i = 0; i < strlen(s); i++) {
		if (s[i] == '(') {
			stack[stack_size++] = i;
		} else if (s[i] == ')') {
			if (stack_size >= 1 &&
			    s[stack[stack_size - 1]] == '(') {
				stack_size--;
			} else {
				stack[stack_size++] = i;
			}
		}
	}
	index = 0;
	for (i = 0; i < strlen(s); i++) {
		if (stack_size >= 1 && i == stack[index]) {
			stack_size--;
			index++;
			continue;
		} else {
			ans[ans_size++] = s[i];
		}
	}
    ans[ans_size] = 0;
	free(stack);
	return ans;
}
```