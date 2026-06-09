### 解题思路
建立一个新的数据结构struct NUM_INX，将num和num所在的inx都保存起来，然后对struct NUM_INX进行排序，再根据inx打印奖牌信息即可

![image.png](https://pic.leetcode-cn.com/28d85dfcffe60258f355cd96ec9fdde6c8af540490c9090875f6b4544ddc12e4-image.png)


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define STR_SIZE 13
struct NUM_INX {
	int num;
	int inx;
};
int cmp(const void *a, const void *b)
{
	return ((struct NUM_INX *)a)->num < ((struct NUM_INX *)b)->num;
}
char** allocRlt(int numsSize)
{
	int i, j;
	char **rlt = NULL;
	rlt = (char**)calloc(numsSize, sizeof(char*));
	if (rlt == NULL) {
		return NULL;
	}
	for (i = 0; i < numsSize; i++) {
		rlt[i] = (char*)calloc(STR_SIZE, sizeof(char));
		if (rlt[i] == NULL) {
			break;
		}
	}
	if (i == numsSize) {
		return rlt;
	}
	for (j = 0; j < i; j++) {
		free(rlt[j]);
	}
	free(rlt);
	return NULL;
}
char ** findRelativeRanks(int* nums, int numsSize, int* returnSize){
	int i;
	struct NUM_INX *numInx = NULL;
	char **rlt = NULL;
	numInx = (struct NUM_INX*)calloc(numsSize, sizeof(struct NUM_INX));
	if (numInx == NULL) {
		return NULL;
	}
	rlt = allocRlt(numsSize);
	if (rlt == NULL) {
		free(numInx);
		return NULL;
	}
	for (i = 0; i < numsSize; i++) {
		numInx[i].num = nums[i];
		numInx[i].inx = i;
	}
	qsort(numInx, numsSize, sizeof(struct NUM_INX), cmp);
	for (i = 0; i < numsSize; i++) {
		if (i >= 3) {
			sprintf(rlt[numInx[i].inx], "%d", i + 1);
		} else if (i == 0) {
			sprintf(rlt[numInx[0].inx], "%s", "Gold Medal");
		} else if (i == 1) {
			sprintf(rlt[numInx[1].inx], "%s", "Silver Medal");
		} else if (i == 2) {
			sprintf(rlt[numInx[2].inx], "%s", "Bronze Medal");
		}
	}
	
	free(numInx);
	*returnSize = numsSize;
	return rlt;
}
```