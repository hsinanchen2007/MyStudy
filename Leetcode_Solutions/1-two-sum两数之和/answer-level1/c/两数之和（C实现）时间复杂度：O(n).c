解题思路：
    一次循环，查找和与元素的差是否存在，用哈希表构建元素和位置的映射。

```c []
#include <stdio.h>

#define N 13

// 哈希函数（除留余数法）
int HS(int key) {
	return key % N;
}

// 在哈希表中查找key，若找到返回其所在的位置，否则将key插入哈希表或表满则返回-1
int hash_table(int key, int m, int addr[]) {
	int i, j;
	
	i = HS(key);
	if (addr[i] == key) {
		return i;
	}

	j = (i + 1) % m; // 线性再散列处理冲突
	while (addr[j] != key && addr[j] != 0) {
		if (j != i) {
			j = (j + 1) % m;
		}
		else {
			return -1;
		}
	}

	if (addr[j] == key)
		return j;

	// 若找到空位置则插入
	if (addr[j] == 0) {
		addr[j] = key;
		return j;
	}

}

int twoSum(int* num, int numSize, int target, int* returnSize) {
	int i, pos, diff;
	int addr[N];

	for (i = 0; i < N; i++) {
		addr[i]=0;
	}

	for (i = 0; i < numSize; i++) {
		hash_table(num[i], N, addr);
	}

	for (i = 0; i < numSize; i++) {
		diff = target - num[i];
		pos = hash_table(diff, N, addr);
		if(pos != -1 && pos != i) {
			returnSize[0] = num[i];
			returnSize[1] = addr[pos];
			return;
		}
	}

	returnSize[0] = 0;
	returnSize[1] = 0;
}


int main() {
	int numSize = 4;
	int num[4] = {2, 7, 11, 15};
	int target = 9;
	int * returnSize = (int *)malloc(sizeof(int) * 2);
	
	twoSum(num, numSize, target, returnSize);
	printf("num1=%d, num2=%d", returnSize[0], returnSize[1]);
}


```



复杂度分析：
    空间复杂度：O(n)
    时间负责度：O(n)


