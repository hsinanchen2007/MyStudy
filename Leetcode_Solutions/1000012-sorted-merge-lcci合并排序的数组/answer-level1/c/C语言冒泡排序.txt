### 解题思路

* 执行用时 :4 ms, 在所有 C 提交中击败了96.88%的用户
* 内存消耗 :7.3 MB, 在所有 C 提交中击败了100.00%的用户
* （问号脸）

### 代码

```c

// BubbleSort
void BubbleSort(int* X, int size) {
	int i, j, temp;
	bool flag;
	for(i = 0; i < size-1; i++) {
		flag = false;
		for(j = size-1; j > i; j--) {
			if(X[j-1] > X[j]) {
				temp = X[j];
				X[j] = X[j-1];
				X[j-1] = temp;
				flag = true;
			}
		}
		if(flag == false) {
			return ;
		}
	}
}

void merge(int* A, int ASize, int m, int* B, int BSize, int n){
	int i = 0, j = 0;
	while(i < ASize && j < BSize) {
        if(A[i] == 0) {
            A[i] = B[j];
            j++;
        }
        i++;
	}
	BubbleSort(A, ASize);
}
```