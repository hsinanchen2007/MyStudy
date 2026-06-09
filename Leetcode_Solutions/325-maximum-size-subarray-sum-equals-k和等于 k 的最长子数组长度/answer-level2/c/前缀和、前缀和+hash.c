### 解题思路
前缀后之后O(n^2)暴力求解，也能通过，耗时：1332 ms
前缀和结合hash，可快速找出答案，需要注意的是前缀和下标是从1开始的，O(n)，耗时：68 ms

### 代码
【前缀和暴力】

```
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int maxSubArrayLen(int* nums, int numsSize, int k){
    int *preSum = (int *)calloc(1, sizeof(int) * (numsSize + 1));
    int i, tmp, j, ans;

    if (numsSize == 0) {
        return 0;
    }

    for (i = 0; i < numsSize; i++) {
        preSum[i + 1] = preSum[i] + nums[i];
    }
    ans = 0;
    for (i = 0; i < numsSize; i++) {
        for (j = numsSize - 1; j >= i; j--) {
            if (preSum[j + 1] - preSum[i] == k) {
                ans = MAX(ans, j - i + 1);
            }
        }
    }
    free(preSum);
    return ans;
}
```


【前缀和+hash】
```c
#include <stdio.h>
//#include "uthash.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct HashEntry {
	int sum;
	int minIndex;
	UT_hash_handle hh;
};

static struct HashEntry *g_users;

static int FindSum(int sum)
{
	struct HashEntry *p;

	HASH_FIND_INT(g_users, &sum, p);
	if (p == NULL) {
		return -1;
	}
	return p->minIndex;
}

static void AddSum(int sum, int index)
{
	struct HashEntry *p;
	HASH_FIND_INT(g_users, &sum, p);
	if (p == NULL) {
		p = (struct HashEntry *)calloc(1, sizeof(struct HashEntry));
		p->sum = sum;
		p->minIndex = index;
		HASH_ADD_INT(g_users, sum, p);
		return;
	}
	if (index < p->minIndex) {
		p->minIndex = index;
	}
}

int maxSubArrayLen(int* nums, int numsSize, int k){
	int i, sum, j, ans;

	if (numsSize == 0) {
		return 0;
	}

	g_users = NULL;
	sum = 0;
	ans = 0;
	AddSum(0, 0);
	for (i = 0; i < numsSize; i++) {
		sum += nums[i];
		j = FindSum(sum - k);
		if (j != -1) {
			ans = MAX(ans, i - j + 1);
		}
		AddSum(sum, i + 1);
	}
	return ans;
}
```