```
//总体思路：下一个丑数即已经确定的丑数与质因数乘积的最小值
#define MIN(x,y) (x < y ? x : y)
int nthSuperUglyNumber(int n, int* primes, int primesSize) {
	int i;
	int min = INT_MAX;
	int count = 1; //stack数量
	//用来存储最终计算完成后的丑数的数组
	int *stack = (int*)malloc(sizeof(int) * n);
	memset(stack, 0, sizeof(int) * n);
	stack[0] = 1;
	//动态分配大小为primesSize的指针数组，初始值都指向stack
	int **queue = (int**)malloc(sizeof(int*) * primesSize);
	memset(queue, 0, sizeof(int*) * primesSize);
	for (i = 0; i < primesSize; i++) {
		queue[i] = stack;
	}
	while (count < n) {
		min = INT_MAX;
		//每次循环，求取queue[i] * primes[i]的最小值，即下一个丑数
		for (i = 0; i < primesSize; i++) {
			min = MIN(MIN(primes[i] * (*(queue[i])), INT_MAX), min);
		}
		stack[count] = min;
		//当queue[i] * primes[i]小于最小值时，需要移动queue[i]的指针到下一个丑数
		for (i = 0; i < primesSize; i++) {
			if (*(queue[i]) * primes[i] <= min) {
				queue[i]++;
			}
		}
		count++;
	}
	return stack[count - 1];
}
```
