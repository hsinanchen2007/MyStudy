/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* prevPermOpt1(int* A, int ASize, int* returnSize){
	if (ASize <= 0) {
		return NULL;
	}
	if(A == NULL || returnSize == NULL) {
		return NULL;
	}
	if (ASize == 1) {
		*returnSize = 1;
		return A;
	}
	*returnSize = ASize;
	for (int i = ASize - 2; i >= 0; i--) {
		if (A[i] <= A[i + 1]) {
			continue;
		}
		int exchange = 0;
		int max = -1;
		int idx = -1;
		for (int j = i + 1; j < ASize; j++) {
			if (A[j] >= A[i]) {
				break;
			}
			exchange = 1;
			if (max < A[j]) {
				max = A[j];
				idx = j;
			}
		}
		if (exchange) {
			int tmp = A[i];
			A[i] = A[idx];
			A[idx] = tmp;
			return A;
		}
	}
	return A;
}
