### 解题思路
UTHASH qsort

### 代码

```c
typedef struct {
	char *string;
	int count;
	int *array;
	UT_hash_handle hh;
} GANode;
GANode *GAHead;

void addGANode(char *keyString, int pos) {
	GANode *fnd, *new;
	HASH_FIND(hh, GAHead, keyString, strlen(keyString)*sizeof(char), fnd);
	if (fnd != NULL) {
		fnd->array = (int *)realloc(fnd->array, (fnd->count + 1)*sizeof(int));
		fnd->array[fnd->count] = pos;
		fnd->count++;
	} else {
		new = (GANode *)calloc(1, sizeof(GANode));
		new->array = (int *)calloc(1, sizeof(int));
		new->array[0] = pos;
		new->count = 1;
		new->string = (char *)calloc(strlen(keyString) + 1, sizeof(char));
		memcpy(new->string, keyString, strlen(keyString)*sizeof(char));
		HASH_ADD(hh, GAHead, string[0], strlen(new->string), new);
	}
}

int cmpChar(const void *a, const void *b) {
	return *(char *)a - *(char *)b;
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
	int i, count;
	char *sortedString;
	GANode *cur, *tmp;
	char ***ret;

	for (i = 0; i < strsSize; i++) {
		sortedString = (char *)calloc(strlen(strs[i]) + 1, sizeof(char));
		memcpy(sortedString, strs[i], strlen(strs[i])*sizeof(char));
		qsort(sortedString, strlen(strs[i]), sizeof(char), cmpChar);
		addGANode(sortedString, i);
		free(sortedString);
	}

	ret = (char ***)calloc(HASH_COUNT(GAHead), sizeof(char **));
	*returnColumnSizes = (int *)calloc(HASH_COUNT(GAHead), sizeof(int));
	count = 0;
	HASH_ITER(hh, GAHead, cur, tmp) {
		ret[count] = (char **)calloc(cur->count, sizeof(char *));
		for (i = 0; i < cur->count; i++) {
			ret[count][i] = (char *)calloc(strlen(cur->string) + 1, sizeof(char));
			memcpy(ret[count][i], strs[cur->array[i]], strlen(cur->string));
		}
		(*returnColumnSizes)[count] = cur->count;
		count++;
		HASH_DEL(GAHead, cur);
		free(cur->array);
		free(cur);
	}

	*returnSize = count;
	return ret;
}
```