此题关键难以理解的是 最大可能排列： 指新排列构成的数是仅次于当前排列数值的排列值，即比它小且最接近于它的数值的那个排列
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
		if (A[i] > A[i + 1]) { // 逆向找到第一次逆序的
			int j = ASize - 1;
			for (;j > i; j--) {
				if (A[j] >= A[i]) { // 如果后面的数据不必目标小，继续循环
					continue;
				}
				if (A[j] == A[j - 1]) { // 如果自身出现多个重复，在找到最前面的那个
					continue;
				}
				int tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
				return A;
			}
		}
	}
	return A;
}
