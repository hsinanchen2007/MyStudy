
### 代码
【二分】
```
int LowBound(int* nums, int numsSize, int tar)
{
    int left, right, mid;
    left = 0;
    right = numsSize;
    while (left < right) {
        mid = (left + right) / 2;
        if (nums[mid] >= tar) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int UpBound(int* nums, int numsSize, int tar)
{
    int index;
    index = LowBound(nums, numsSize, tar + 1);
    return index - 1;
}

bool canDivideIntoSubsequences(int* nums, int numsSize, int K){
    int i, len, maxLen;

    maxLen = 0;
    for (i = 0; i < numsSize; i++) {
        len = UpBound(nums, numsSize, nums[i]) - LowBound(nums, numsSize, nums[i]) + 1;
        if (len > maxLen) {
            maxLen = len;
        }
    }
    if (maxLen * K > numsSize) {
        return false;
    }
    return true;
}
```

【uthahs】
```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct HashEntry {
	int userId;
	int cnt;
	UT_hash_handle hh;
};

static struct HashEntry *g_users;

static void AddNode(int userId)
{
	struct HashEntry *node;
	HASH_FIND_INT(g_users, &userId, node);
	if (node != NULL) {
		node->cnt++;
		return;
	}
	node = (struct HashEntry *)calloc(1, sizeof(struct HashEntry));
	node->userId = userId;
	node->cnt = 1;
	HASH_ADD_INT(g_users, userId, node);
};

bool canDivideIntoSubsequences(int* nums, int numsSize, int K){
    int i, len, maxCnt;
    struct HashEntry *cur, *tmp;

    g_users = NULL;
    for (i = 0; i < numsSize; i++) {
        AddNode(nums[i]);
    }
    
	maxCnt = 0;
	HASH_ITER(hh, g_users, cur, tmp) {
		maxCnt = MAX(maxCnt, cur->cnt);
	}    
    //printf("%d", maxCnt);
    if (maxCnt * K > numsSize) {
        return false;
    }
    return true;
}
```