### 解题思路
1、使用递归思路遍历所有值
2、将不合法的不进行记录

### 代码

```c
#define INIT_MAX_SIZE 4096

int IsValid(char *parenthes)
{
	int left;
	left = 0;
	int index;
	for (index = 0; parenthes[index] != '\0'; index++) {
		if (parenthes[index] == '(') {
			left++;
		}
		else if (parenthes[index] == ')') {
			left--;
		}
		if (left < 0) {
			return 0;
		}
	}

	if ((left != 0) || (index == 0)) {
		return 0;
	}
	return 1;
}

void AddOneRecord(char ***retStr, int *returnSize, char *parenthes)
{
	if (!IsValid(parenthes)) {
		return;
	}
	char **insert = NULL;
	static int num = INIT_MAX_SIZE;
	if (*returnSize == 0) {
		insert = (char **)malloc(num * sizeof(char *));
		if (insert == NULL) {
			return;
		}
		memset(insert, 0x0, num * sizeof(char *));
		*retStr = insert;
	}

	insert = *retStr;
	if (*returnSize >= num) {
		char **temp = (char **)malloc(num * 2 * sizeof(char *));
		if (temp == NULL) {
			return;
		}
		memset(temp, 0x0, num * 2 * sizeof(char *));
		memcpy(temp, insert, num * sizeof(char *));
		free(insert);
		insert = temp;
	}

	int len = strlen(parenthes);
	char *input = (char *)malloc((len + 1) * sizeof(char));
	if (input == NULL) {
		return;
	}
	strcpy(input, parenthes);
	input[len] = '\0';

	insert[*returnSize] = input;
	*returnSize = *returnSize + 1;
	return;
}

void CreateParenthesis(int left, int right, int n, char ***retStr, int *returnSize, char *parenthes)
{
	if ((right == 0) && (left == 0)) {
		AddOneRecord(retStr, returnSize, parenthes);
		return;
	}

	if (left > 0) {
		char *newStr = (char *)malloc(sizeof(char) * (2 * n + 1));
		if (newStr != NULL) {
			memset(newStr, 0x0, sizeof(char) * (2 * n + 1));
			strcpy(newStr, parenthes);
			strcat(newStr, "(");
			CreateParenthesis(left - 1, right, n, retStr, returnSize, newStr);
			free(newStr);
		}
	}

	if (right > 0) {
		char *newStr = (char *)malloc(sizeof(char) * (2 * n + 1));
		if (newStr != NULL) {
			memset(newStr, 0x0, sizeof(char) * (2 * n + 1));
			strcpy(newStr, parenthes);
			strcat(newStr, ")");
			CreateParenthesis(left, right - 1, n, retStr, returnSize, newStr);
			free(newStr);
		}
	}
	return;
}

/* *
* Note: The returned array must be malloced, assume caller calls free().
*/
char **generateParenthesis(int n, int *returnSize)
{
	int left;
	int right;

	left = n;
	right = n;

	*returnSize = 0;
	char **retStr = NULL;
	char *parenthes = (char *)malloc(sizeof(char) * (2 * n + 1));
	memset(parenthes, 0x0, sizeof(char) * (2 * n + 1));
	CreateParenthesis(left, right, n, &retStr, returnSize, parenthes);
	free(parenthes);
	return retStr;
}
```