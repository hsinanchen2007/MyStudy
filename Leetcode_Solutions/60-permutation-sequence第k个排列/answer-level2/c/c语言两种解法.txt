法一：
把k从0计数，k = index(0)*(n-1)! + index(1)*(n-2)! + index(n-1) *(0)!
index(i) 是 n个数按升序排列，i个序列的下标。并且当第nums[i]数字被选择后，后面的序列不能再选择它
```
int calcFactorial( int l) {
	if (l == 0 || l == 1) {
		return 1;
	}
	return l * calcFactorial(l - 1);
}


char * getPermutation2(int n, int k) {

	char *result = (char *)malloc(n + 1);
	result[n] = '\0';

	int nums[9] = { 0 };
	for (int i = 0; i < n; i++) {
		nums[i] = i + 1;
	}
	
	int index, value = k - 1, temp = n;
	for (int i = 0; i < n;i++) {
		index = value / calcFactorial(n - i - 1);
		value = value % calcFactorial(n - i - 1);
		result[i] = nums[index] + '0';
		
		if (index != temp - 1) {
			memmove(nums + index, nums + index + 1, (temp - index - 1) * sizeof (int));
		}
		temp--;
	}
	return result;
}
```

法二：
利用leecode 31题,循环k次获取结果
```
int compareInt(void const *v1, void const *v2) {
	return *(int *)v1 > *(int*)v2;
}

void nextPermutation(int* nums, int numsSize) {
	if (nums == NULL || numsSize == 0) {
		return;
	}
	int i, j, temp;
	for (i = numsSize - 1; i >= 1; i--) {
		if (nums[i] <= nums[i - 1] ) {
			continue;
		}
		for (j = numsSize - 1; j >= i; j--) {
			if (nums[j] > nums[i -1]) {
				temp = nums[i - 1];
				nums[i - 1] = nums[j];
				nums[j] = temp;
				qsort(nums + i, numsSize - i, sizeof(int), compareInt);
				return;
			}
		}
		
	}
	
	qsort(nums, numsSize, sizeof(int), compareInt);
	
	return;
}

char * getPermutation(int n, int k) {
	int nums[9] = {0};
	for (int i = 0; i < n; i++) {
		nums[i] = i + 1;
	}

	for (int j = 0; j < k - 1; j++) {
		nextPermutation(nums, n);
	}
	char *result = (char *)malloc(n + 1);
	result[n] = '\0';
	for (int i = 0; i < n; i++) {
		result[i] = nums[i] + '0';
	}
	return result;
}

```
