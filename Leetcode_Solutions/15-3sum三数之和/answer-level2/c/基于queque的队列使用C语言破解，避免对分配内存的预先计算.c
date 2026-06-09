#define MAX 3

typedef struct _item {
	int *data;
	struct _item *next;
} Item;

typedef struct {
	Item *header;
	Item *tail;
} Queue;

int Isempty(Queue *q)
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
	each->data = val;
	each->next = NULL;
	if (Isempty(q)) {
		q->header = q->tail = each;
		return;
	}
	q->tail->next = each;
	q->tail = each;
}

void Dequeue(Queue *q, int **ret, int idx)
{
	if (Isempty(q)) {
		return;
	}
	Item *each = NULL;
	while ((each = q->header) != NULL) {
		q->header = q->header->next;
		ret[idx] = each->data;
		idx++;
		free(each);
	}
}

int Cmp(const void *a, const void *b)
{
	return *((int *)a) - *((int *)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	*returnSize = 0;
	if (numsSize < MAX) {
		return NULL;
	}
	qsort(nums, numsSize, sizeof(nums[0]), Cmp);
	if (nums[0] > 0 || nums[numsSize - 1] < 0) {
		return NULL;
	}
	//int **ret = (int **)calloc(6 * (numsSize + 1), sizeof(int *));
	//if (ret == NULL) {
		//exit(-1);
	//}
	Queue queue = {NULL, NULL};
	for (int i = 0; i < numsSize - 2; i++) {
		if (nums[i] > 0) {
			break;
		}
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		int j = i + 1;
		int k = numsSize -1;
		while (j < k) {
			if (nums[i] + nums[j] + nums[k] < 0) {
				j++;
				while (j < k && nums[j] == nums[j - 1]) {
					j++;
				}
				continue;
			}
			if (nums[i] + nums[j] + nums[k] > 0) {
				k--;
				while (j < k && nums[k] == nums[k + 1]) {
					k--;
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
			EnQueue(&queue, res);
			//ret[*returnSize] = res;
			*returnSize += 1;
			j++;
			k--;
			while (j < k && nums[j] == nums[j - 1]) {
				j++;
			}
			while (j < k && nums[k] == nums[k + 1]) {
				k--;
			}
		}
	}
	if (*returnSize == 0) {
		//free(ret);
		return NULL;
	}
	int **ret = (int **)calloc(*returnSize, sizeof(int *));
	*returnColumnSizes = (int *)calloc(*returnSize, sizeof(int));
	if (*returnColumnSizes == NULL || ret == NULL) {
		exit(-1); 
	}
	Dequeue(&queue, ret, 0);
	for (int i = 0; i < *returnSize; i++) {
		(*returnColumnSizes)[i] = MAX;
	}
	return ret;
}