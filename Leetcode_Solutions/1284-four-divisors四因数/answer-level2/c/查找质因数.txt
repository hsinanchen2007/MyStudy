### 解题思路
此处撰写解题思路
1.小于9的数先单独计算。
2.判断是否为平方数，如果是平方数，肯定不符合四因数条件。
3.判断因数是否为质数，如果两个因数都为质数，符合条件。
4.判断是否为立方数，并且其中一个为质数，也符合条件
### 代码

```c
#define MAX_NAM 100000

#define min(x, y) ((x) > (y) ? (y) : (x))

#define max(x, y) ((x) > (y) ? (x) : (y))

int g_sum = 0;

int g_visit[MAX_NAM] = { 0 };

int IsPrime(int a)
{
	if (a < 4) {
		return 1;
	}

	int m = sqrt(a);

	int i;
	int ret = -1;
	for (i = 2; i <= m; i++) {
		ret = a % i;

		if (ret == 0) {
			return 0;
		}
	}
	return 1;
}

int FindNum(int num)
{
	printf("0 num %d \n", num);
	if (num < 6) {
		return 0;
	}
	if (num == 6) {
		g_sum = g_sum + 12;
		return 12;
	}
	if (num == 7) {
		return 0;
	}
	if (num == 8) {
		g_sum = g_sum + 15;
		return 15;
	}
	if (num == 9) {
		return 0;
	}

	int divCnt = 0;
	memset(g_visit, 0, MAX_NAM * sizeof(int));
	printf("1 num %d \n", num);

	int i;
	int ret;
	for (i = 2; i < num/2; i++) {
		if (g_visit[i] == 0) {
			if (num % i == 0) {
				ret = num / i;
				divCnt++;
				g_visit[i] = 1;
				g_visit[ret] = 1;
				printf("ret %d i %d \n", ret, i);
				break;
			}
		}
	}
	if (divCnt == 0) {
		return 0;
	}
	if (ret == i) {
		return 0;
	}

	int temp = IsPrime(ret) && IsPrime(i);
	if (temp == 1) {
		g_sum = g_sum + 1 + num + ret + i;
		return g_sum;
	}

	temp = IsPrime(i);
	if (temp == 1 && i * i == ret) {
		g_sum = g_sum + 1 + num + ret + i;
		return g_sum;
	}
	return 0;
}

int sumFourDivisors(int* nums, int numsSize){
	printf("numsSize %d nums[0] %d \n", numsSize, nums[0]);
	g_sum = 0;

	int i;
	for (i = 0; i < numsSize; i++) {
		FindNum(nums[i]);
	}

	return g_sum;
}
```