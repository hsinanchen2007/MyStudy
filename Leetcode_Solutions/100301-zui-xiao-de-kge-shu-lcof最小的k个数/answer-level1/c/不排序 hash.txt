排序太无聊
C写堆麻烦
换个思路

hash计算个数，从小到大列出来就可以了

#define N 10001

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int *hash = (int *)malloc(sizeof(int) * N);
	memset(hash, 0, sizeof(int) * N);
	
	for (int i = 0; i < arrSize; i++) {
	    hash[arr[i]]++;
	}
	
	int *ans = (int *)malloc(sizeof(int) * k);
	memset(ans, 0, sizeof(int) * k);
	
	int j = 0;
	for (int i = 0; i < N && j < k; i++) {
	    while (hash[i] != 0 && j < k) {
		    ans[j] = i;
			j++;
            hash[i]--;
		}
	}
	*returnSize = j;
	return ans;
}