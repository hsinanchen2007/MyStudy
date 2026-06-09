```

typedef struct tagMap {
	int value;
	int pos;
} MAP_S;

int compare(const void* p1, const void* p2)
{
	return ((MAP_S*)p1)->value  - ((MAP_S*)p2)->value;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int left;
	int right;
	int sum;
	int posLeft;
	int posRight;
	int* result = NULL;
	MAP_S* sortMaps = NULL;

	*returnSize = 0;
	if (nums == NULL || numsSize < 2) {
		return NULL;
	}
	sortMaps = (MAP_S *)malloc(numsSize * sizeof(MAP_S));
	for (int i = 0; i < numsSize; i++) {
		sortMaps[i].pos = i;
		sortMaps[i].value = nums[i];
	}

	qsort(sortMaps, numsSize, sizeof(MAP_S), compare);
	left = 0;
	right = numsSize - 1;

	while (left < right) {
		sum = sortMaps[left].value + sortMaps[right].value;
		if (sum < target) {
			left++;
		}
		else if (sum > target) {
			right--;
		} else {
			break;
		}
	}

	if (left != right) {
		result = (int *)malloc(2 * sizeof(int));
		posLeft = sortMaps[left].pos;
		posRight = sortMaps[right].pos;
		result[0] = posLeft > posRight ? posRight : posLeft;
		result[1] = posLeft > posRight ? posLeft : posRight;
        *returnSize = 2;
		free(sortMaps);
		return result;
	}
	free(sortMaps);
	return NULL;
}
```

hash 法

```

typedef struct node {
	int value;
	int pos;
	struct node* pNext;
} NODE_S;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int     *result = NULL;
	NODE_S **hash = NULL;
	NODE_S  *pNode = NULL;
    int i;

	*returnSize = 0;
	if (nums == NULL || numsSize < 2) {
		return NULL;
	}

	hash = (NODE_S**)malloc(numsSize * sizeof(NODE_S *));
    memset(hash, 0 , numsSize * sizeof(NODE_S *));
	for (i = 0; i < numsSize; i++) {
		pNode = hash[abs(target - nums[i]) % numsSize];
		while (pNode != NULL && (pNode->value + nums[i] != target)) {
			pNode = pNode->pNext;
		}

		if (pNode != NULL) {
			result = (int*)malloc(2 * sizeof(int));
			result[0] = pNode->pos;
			result[1] = i;
			*returnSize = 2;
			free(hash);
			return result;
		}
		pNode = (NODE_S*)malloc(sizeof(NODE_S));
        pNode->pos = i;
        pNode->value = nums[i];
		pNode->pNext = hash[abs(nums[i]) % numsSize];
		hash[abs(nums[i]) % numsSize] = pNode;
	}

	free(hash);
	return NULL;
}
```
