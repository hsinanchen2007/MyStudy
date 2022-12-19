偶数使用左指针，奇数使用右指针
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    int left, right, i;
	int *rlt;
	rlt = (int*)calloc(ASize, sizeof(int));
	if (rlt == NULL) {
		return NULL;
	}
	left = 0;
	right = ASize - 1;
	i = 0;
	while(left <= right) {
		if (A[i] % 2 == 0) {
			rlt[left] = A[i];
			left++;
		} else {
			rlt[right] = A[i];
			right--;
		}
		i++;
	}
	*returnSize = ASize;
	return rlt;
}
```
