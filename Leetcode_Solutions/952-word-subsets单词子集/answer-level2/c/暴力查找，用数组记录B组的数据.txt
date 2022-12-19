### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int DebugF(int *flag, int size)
{
	int i;
	for (i = 0; i < 30; i++) {
		printf("%d ", flag[i]);
	}
	return 0;
}

int CheckSubset(char *A, int *flagB)
{
	int *flagC = (int *)malloc(30 * sizeof(int));
	memset(flagC, 0, 30 * sizeof(int));
	memcpy(flagC, flagB, 30 * sizeof(int));

	int i;
	int aLen = strlen(A);
	for (i = 0; i < aLen; i++) {
		if (flagC[A[i] - 'a'] != 0) {
			flagC[A[i] - 'a']--;
		}
	}
	for (i = 0; i < 30; i++) {
		if (flagC[i] != 0) {
			return -1;
		}
	}
	free(flagC);
	return 0;
}

int *CreatSubset(char **B, int BSize)
{
	int *f1 = (int *)malloc(30 * sizeof(int));
	memset(f1, 0, 30 * sizeof(int));
	int *flagB = (int *)malloc(30 * sizeof(int));
	memset(flagB, 0, 30 * sizeof(int));

	int i;
	int j;
	for (i = 0; i < BSize; i++) {
		memset(f1, 0, 30 * sizeof(int));
		for (j = 0; j < strlen(B[i]); j++) {
			//printf("B %c %d \n", B[i][j], B[i][j] - 'a');
			f1[B[i][j] - 'a']++;
		}
		for (j = 0; j < 30; j++) {
			if (flagB[j] < f1[j]) {
				flagB[j] = f1[j];
			}
		}
	}
	free(f1);
	return flagB;
}


char ** wordSubsets(char ** A, int ASize, char ** B, int BSize, int* returnSize){

	printf("ASize %d BSize %d \n", ASize, BSize);

	int *flagB = CreatSubset(B, BSize);
	printf("flagB \n");
	DebugF(flagB, 30);

	int *flagA = (int *)malloc(ASize * sizeof(int));
	memset(flagA, 0, ASize * sizeof(int));

	int i;
	int cnt = 0;
	for (i = 0; i < ASize; i++) {
		if (CheckSubset(A[i], flagB) == 0) {
			flagA[i] = 1;
			cnt++;
		}
	}

	char **ans = (char **)malloc(cnt * sizeof(char *));
	cnt = 0;
	for (i = 0; i < ASize; i++) {
		if (flagA[i] == 1) {
			ans[cnt] = (char *)malloc(strlen(A[i]) + 1);
			memset(ans[cnt], 0, strlen(A[i]) + 1);
			memcpy(ans[cnt], A[i], strlen(A[i]));
			cnt++;
		}
	}
	*returnSize = cnt;
	return ans;
}
```