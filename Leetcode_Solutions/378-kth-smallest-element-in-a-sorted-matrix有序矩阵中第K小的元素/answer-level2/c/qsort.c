### 解题思路
行用时 :48 ms, 在所有 C 提交中击败了71.39%的用户
内存消耗 :9.2 MB, 在所有 C 提交中击败了100.00%的用户
### 代码

```c
/*
1.看到搞大小的，莫名就有qsort的冲动~~
2.1次通过，顺利~~
*/
int Com(const void * a, const void * b)
{
	int a1 = *(int *)a;
	int b1 = *(int *)b;
	return a1 > b1;
}

void Dis(int *num, int size)
{
    printf("%d", __LINE__);
    for (int i = 0; i < size; i++) {
        printf("%d, ", num[i]);
    }
    printf("\n");

}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k)
{
	const int size = matrixSize * *matrixColSize;
    const int len = size * sizeof(int);
    const int unit = *matrixColSize * sizeof(int);
	int *nums = (int *)malloc(len);
	memset(nums, 0, len);
	for (int i = 0; i < matrixSize; i++) {
		memcpy(&nums[i * *matrixColSize], matrix[i], unit);
	}
	qsort(nums, matrixSize * *matrixColSize, sizeof(int), Com);
    //Dis(nums, size);
	int ret = nums[k - 1];
	//Dis(nums, size);
    free(nums);
	return ret;
}
```