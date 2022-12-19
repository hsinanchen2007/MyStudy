### 解题思路
给n对括号，随意排列，使得排列出来的括号序列没问题。

用一个栈记录排列，进行dfs
如果括号用光，输出栈中的字符串
如果（ 有余量，添加（
如果栈里 ）的数量小于栈里（ 的数量，添加 ）

因为不知道有多少合理的排列，要返回的char\*\*要开很大（1000 在测试用例n=8 的时候不通过）
### 代码

```c
void dfs(char* stack, int top, int n, int leftNum, int rightNum, char** result, int* returnSize)
{
	if (leftNum == n && rightNum == n)
	{
		result[*returnSize] = (char*)malloc(sizeof(char)*n * 2 + 1);
		for (int i = 0; i < n * 2; ++i)
			result[*returnSize][i] = stack[i];
		result[*returnSize][n * 2] = '\0';
		++(*returnSize);
		return;
	}
	if (leftNum < n)
	{
		stack[top] = '(';
		dfs(stack, top+1, n, leftNum + 1, rightNum, result, returnSize);
	}
	if (leftNum > rightNum)
	{
		stack[top] = ')';
		dfs(stack, top+1, n, leftNum, rightNum + 1, result, returnSize);
	}
}
char ** generateParenthesis(int n, int* returnSize) {
	char* stack = (char*)malloc(sizeof(char) * 2 * n+1);
	char** result = (char**)malloc(sizeof(char*) * 2048);
	*returnSize = 0;
	dfs(stack, 0, n, 0, 0, result, returnSize);
	return result;
}
```