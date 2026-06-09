### 解题思路
单调栈，速度和内存消耗都一般，只能说还算工整吧

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct DStack {
	int val[2];
} DStack;

DStack* createStack(int* nums2, int nums2Size, int *retSize)
{
	int i, cnt = 0;
	int *buf = NULL;
	DStack *stack = NULL;
	int size = 0;
	
	buf = (int*)calloc(nums2Size, sizeof(int));
	if (buf == NULL) {
		return NULL;
	}
	stack = (DStack*)calloc(nums2Size, sizeof(DStack));
	if (stack == NULL) {
		free(buf);
		return NULL;
	}
	
	for (i = 0; i < nums2Size; i++) {
		while (cnt > 0 && nums2[i] > buf[cnt - 1]) {
			stack[size].val[0] = buf[cnt - 1];
			stack[size].val[1] = nums2[i];
			size++;
			cnt--;
		}
		buf[cnt++] = nums2[i];
	}
	for (i = 0; i < cnt; i++) {
		stack[size].val[0] = buf[i];
		stack[size].val[1] = -1;
		size++;
	}
	free(buf);
	*retSize = size;
	return stack;
}
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
	int i, j;
	int size = 0;
	DStack *stack = NULL;
	int *rlt = NULL;
	rlt = (int*)calloc(nums1Size, sizeof(int));
	if (rlt == NULL) {
		*returnSize = 0;
		return NULL;
	}
	stack = createStack(nums2, nums2Size, &size);
	if (stack == NULL) {
		free(rlt);
		*returnSize = 0;
		return NULL;
	}
	for (i = 0; i < nums1Size; i++) {
		for (j = 0; j < size; j++) {
			if (stack[j].val[0] == nums1[i]) {
				rlt[i] = stack[j].val[1];
			}
		}
	}
	free(stack);
	*returnSize = nums1Size;
	return rlt;
}
```