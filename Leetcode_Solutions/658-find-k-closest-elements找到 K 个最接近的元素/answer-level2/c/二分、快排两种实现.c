### 解题思路
此处撰写解题思路

【快排】
```
struct TNode {
    int val;
    int sub;
};
static int Comp(void *a, void *b)
{
    struct TNode *pa = (struct TNode *)a;
    struct TNode *pb = (struct TNode *)b;
    if (pa->sub == pb->sub) {
        return pa->val - pb->val;
    }
    return pa->sub - pb->sub;
}

static int Comp1(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize)
{
    struct TNode *tmp = (struct TNode *)calloc(1, sizeof(struct TNode) * arrSize);
    int *ans = (int *)calloc(1, sizeof(int) * arrSize);
    int i;
    for (i = 0; i < arrSize; i++) {
        tmp[i].sub = abs(arr[i] - x);
        tmp[i].val = arr[i];
    }
    qsort(tmp, arrSize, sizeof(struct TNode), Comp);
 
    for (i = 0; i < k; i++) {
        ans[i] = tmp[i].val;
    }
    qsort(ans, k, sizeof(int), Comp1);
    *returnSize = k;
    return ans;
}


```

【二分】
### 代码

```c
#include <stdio.h>
static int FindBegin(int* arr, int arrSize, int x)
{
	int left, right, mid;
	left = 0;
	right = arrSize;

	while (left < right) {
		mid = (left + right) / 2;
		if (arr[mid] >= x) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	if (left == arrSize) {
		return left - 1;
	}
	if (left == 0) {
		return 0;
	}
	if (arr[left] - x < x - arr[left - 1]) {
		return left;
	} else {
		return left - 1;
	}
}

static int Comp(void *a, void *b)
{
	return *(int *)a - *(int *)b;
}

int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize){
	int beginIndex = FindBegin(arr, arrSize, x);
	int cnt = 0;
	int *ans = (int *)calloc(1, sizeof(int) * k);
	int ansIndex = 0;
	int left, right;

	if (arrSize == 0 || k > arrSize) {
		*returnSize = 0;
		return NULL;
	}

	left = beginIndex;
	right = left + 1;
	while (cnt < k) {
		if (left < 0) {
			ans[ansIndex++] = arr[right];
			right++;            
		} else if (right >= arrSize) {
			ans[ansIndex++] = arr[left];
			left--;            
		} else {
			if (x - arr[left] <= arr[right] - x) {
				ans[ansIndex++] = arr[left];
				left--;
			} else {
				ans[ansIndex++] = arr[right];
				right++;
			}            
		}
		cnt++;
	}

	qsort(ans, ansIndex, sizeof(int), Comp);

	*returnSize = k;
	return ans;
}


```