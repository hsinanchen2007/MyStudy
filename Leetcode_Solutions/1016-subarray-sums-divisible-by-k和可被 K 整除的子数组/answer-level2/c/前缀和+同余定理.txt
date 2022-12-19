### 解题思路
此处撰写解题思路

### 代码

```c
/*
(同餘定理運用)

*/
int subarraysDivByK(int* A, int ASize, int K){
	int N = ASize + 1;
	int *P = (int *)malloc(N * sizeof(int));
	memset(P, 0, N * sizeof(int));

	int i;
	for (i = 0; i < ASize; i++) {
		P[i + 1] = P[i] + A[i];
	}

	int *count = (int *)malloc(K * sizeof(int));
	memset(count, 0, K * sizeof(int));
	printf("K %d \n", K);

	// A = [4,5,0,-2,-3,1]
	// P = [0,4,9, 9, 7,4,5]
	// C0 = 2
	// C4 = 4  四个取2个，等于6
	int X;
	for (i = 0; i < N; i++) {
		X = P[i];
		count[(X % K + K) % K]++; // 
	}
	printf("X %d \n", X);


	int ans = 0;
	for (i = 0; i < K; i++) {
		X = count[i];
		ans = ans + X * (X - 1) / 2;
	}
	printf("ans %d \n", ans);

	return ans;
}
```