### 解题思路 
两个指针遍历两个数组，其中一个临时数组保存A数组（A数组要作为结果输出，避免覆盖） 注意一个数组遍历完，剩下一个数组拷贝时候的长度即可。 

### 代码
```
void merge(int* A, int ASize, int m, int* B, int BSize, int n) {
	int *tempA = malloc(sizeof(int) * m);
	memcpy(tempA, A, sizeof(int) * m);
	int idx = 0;
	for (int i = 0,j = 0; i < m || j < n;) {
		if (i >= m) {
			// A数组已经取完
			memcpy(A + idx, B + j, sizeof(int) * (n - j));
			break;
		}
		if (j >= n) {
			// B数组已经取完
			memcpy(A + idx, tempA + i, sizeof(int) * (m - i));
			break;
		}
		if (tempA[i] <= B[j]) {
			A[idx++] = tempA[i];
			i++;
		}
		else{
			A[idx++] = B[j];
			j++;
		}
	}
}
```
