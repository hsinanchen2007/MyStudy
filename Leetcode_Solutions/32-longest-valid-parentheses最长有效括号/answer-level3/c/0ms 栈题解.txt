### 解题思路
消除括号很自然想到栈，使用栈将配对的括号消除，栈中剩余的便是不能消除的，从中计算有效括号的最大长度，为了方便计算，首尾添加两个哨兵；

### 代码

```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestValidParentheses(char * s){
	int sLen = strlen(s);
	int *stack = (int *)calloc(1, sizeof(int) * (sLen + 2));
	int top = 0;
	int i, topIndex, ans;
	ans = 0;
	stack[top++] = -1;
	for (i = 0; i < sLen; i++) {
		if (s[i] == ')') {
			if (top != 1) {
				topIndex = stack[top - 1];
				if (s[topIndex] == '(') {
					top--;
					continue;
				}
			}
		}
		stack[top++] = i;
	}
	stack[top++] = i;
	for (i = 1; i < top; i++) {
		ans = MAX(ans, stack[i] - stack[i - 1] - 1);
	}
	free(stack);
	return ans;
}
```