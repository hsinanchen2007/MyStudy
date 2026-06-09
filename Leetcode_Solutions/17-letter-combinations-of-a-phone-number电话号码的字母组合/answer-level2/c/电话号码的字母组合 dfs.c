/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
const char* g_phoneNum[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
int g_rstIndex = 0;
void dfs(char** rst, int index, int length, char* digits, char* tmp)
{
	int num = digits[index] - '0';
	int tmpLen = strlen(tmp);
	if (index == length) {

		char* tmp1 = (char*)malloc(tmpLen + 1);
		memcpy(tmp1, tmp, tmpLen + 1);
		rst[g_rstIndex++] = tmp1;
		return;
	}

	for (int i = 0; i < strlen(g_phoneNum[num]); i++) {
		tmp[tmpLen] = g_phoneNum[num][i];
		dfs(rst, index + 1, length, digits, tmp);
		tmp[tmpLen] = '\0';
	}
	return;
}


char** letterCombinations(char* digits, int* returnSize) {
	char** rst;
	int len = strlen(digits);

	int rstLen = 1;

    if (len == 0) {
        *returnSize = 0;
        rst = NULL;
        return rst;
    }

	for (int i = 0; i < len; i++)
	{
		int num = digits[i] - '0';
		rstLen = rstLen * strlen(g_phoneNum[num]);
	}

	rst = (char**)malloc(rstLen * sizeof(char*));
	*returnSize = rstLen;
	g_rstIndex = 0;
	char* tmp = (char*)malloc(len + 1);
	memset(tmp, '\0', len + 1);

	dfs(rst, 0, len, digits, tmp);
	free(tmp);
	tmp = NULL;
	return rst;
}