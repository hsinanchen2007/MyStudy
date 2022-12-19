/*
执行用时 :20 ms, 在所有 C 提交中击败了95.44%的用户
内存消耗 :7.9 MB, 在所有 C 提交中击败了90.38%的用户
*/
#define MAX 4
typedef struct _item {
	int *val;
	struct _item *next;
} Item;
typedef struct {
	Item *header;
	Item *tail;
} Queue;
int IsEmpty(const Queue *q)
{
	if (q->header == NULL && q->tail == NULL) {
		return 1;
	}
	return 0;
}
void EnQueue(Queue *q, int *val)
{
	Item *each = (Item *)calloc(1, sizeof(Item));
	if (each == NULL) {
		exit(-1);
	}
	each->val = val;
	if (IsEmpty(q)) {
		q->header = q->tail = each;
		return;
	}
	q->tail->next = each;
	q->tail = each;
}
void DeQueue(Queue *q, int **ret, int idx)
{
	if (IsEmpty(q)) {
		return;
	}
	Item *each = NULL;
	while ((each = q->header) != NULL) {
		q->header = q->header->next;
		ret[idx] = each->val;
		idx++;
		free(each);
	}
}
int Cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
	*returnSize = 0;
	if (numsSize < MAX) {
		return NULL;
	}
	qsort(nums, numsSize, sizeof(nums[0]), Cmp);
	//if (nums[0] > target) { // 对于负数，此处不成立，多个负数的和更小
		//return NULL;
	//}
	Queue queue = {NULL, NULL};
	for (int i = 0; i < numsSize - 3; i++) {
		if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
			break;
		}
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		for (int j = i + 1; j < numsSize - 2; j++) {
			if (j > i + 1 && nums[j] == nums[j - 1]) {
				continue;
			}
			int k = j + 1;
			int m = numsSize - 1;
			if (nums[i] + nums[j] + nums[k] + nums[k + 1] > target) {
				break;
			}
			if (nums[i] + nums[j] + nums[m - 1] + nums[m] < target) {
				continue;
			}
			while (k < m) {
				int tmp = nums[i] + nums[j] + nums[k] + nums[m];
				if (tmp > target) {
					m--;
					while (k < m && nums[m] == nums[m + 1]) {
						m--;
					}
					continue;
				}
				if (tmp < target) {
					k++;
					while (k < m && nums[k] == nums[k -1]) {
						k++;
					}
					continue;
				}
				int *res = (int *)calloc(MAX, sizeof(int));
				if (res == NULL) {
					exit(-1);
				}
				res[0] = nums[i];
				res[1] = nums[j];
				res[2] = nums[k];
				res[3] = nums[m];
				EnQueue(&queue, res);
				*returnSize += 1;
				k++;
				m--;
				while (k < m && nums[k] == nums[k -1]) {
					k++;
				}
				while (k < m && nums[m] == nums[m + 1]) {
					m--;
				}
			}
		}
	}
	if (*returnSize == 0) {
		return NULL;
	}
	int **ret = (int **)calloc(*returnSize, sizeof(int *));
	*returnColumnSizes = (int *)calloc(*returnSize, sizeof(int));
	if (ret == NULL || *returnColumnSizes == NULL) {
		exit(-1);
	}
	DeQueue(&queue, ret, 0);
	for (int i = 0; i < *returnSize; i++) {
		(*returnColumnSizes)[i] = MAX;
	}
	return ret;
}