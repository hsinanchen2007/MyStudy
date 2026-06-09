![1.png](https://pic.leetcode-cn.com/6bd2145f404f8cfab0fa9d13c3ab96423c1bdec9d6c1b5f02d11c085c2e787d9-1.png)

先排序
一、计算负数个数的同时，找出绝对值最小的值；
二、如果负数>K,前K个取绝对值
三、负数<=K,先求绝对值的和；如果(K - neg)是奇数，返回sum - absmin * 2 

```
int largestSumAfterKNegations(int* A, int ASize, int K){
	qsort(A, ASize, sizeof(int), cmq);
	int neg = 0, sum = 0, absmin = abs(A[0]);
	for (int i = 0; i < ASize; i++){
		if (A[i] < 0)
			neg++;
		absmin = absmin < abs(A[i]) ? absmin : abs(A[i]);
	}
	if (neg > K){
		for (int i = 0; i < ASize; i++){
			if (i < K)
				sum += abs(A[i]);
			else
				sum += A[i];
		}
		return sum;
	}
	else
		for (int i = 0; i < ASize; i++)
			sum += abs(A[i]);
	return (K - neg) % 2 ? sum - absmin * 2 : sum;
}
```


