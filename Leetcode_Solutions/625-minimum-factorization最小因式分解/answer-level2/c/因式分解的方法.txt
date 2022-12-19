### 解题思路
此处撰写解题思路
注意要用long long型保存结果后再判断是否溢出int型。
### 代码

```c
/*
625. 最小因式分解
*/
#define I2 2
#define I3 3
#define I5 5
#define I7 7

#define I2P 0
#define I3P 1
#define I5P 2
#define I7P 3

#define N_MAX    4

int dfs(int *arr, int input)
{
	int output = 0;
	int ret = 0;

	printf("input %d \n", input);
	if (input == 1) {
		return 0;
	} else {
		output = input % I7;
		if (output == 0) {
			arr[I7P]++;
			ret = dfs(arr, input / I7);
			return ret;
		}

		output = input % I5;
		if (output == 0) {
			arr[I5P]++;
			ret = dfs(arr, input / I5);
			return ret;
		}

		output = input % I3;
		if (output == 0) {
			arr[I3P]++;
			ret = dfs(arr, input / I3);
			return ret;
		}

		output = input % I2;
		if (output == 0) {
			arr[I2P]++;
			ret = dfs(arr, input / I2);
			return ret;
		}

		return -1;
	}
}

long long CalcTenN(int n)
{
	int m = n;
	long long ret = 1;
	if (m == 0) {
		return ret;
	}
	while (m) {
		ret = ret * 10;
		m--;
	}
	return ret;
}

int smallestFactorization(int a) {

	int i;
	int arr[N_MAX] = { 0 };

	if (a <= 1) {
		return a;
	}

	int ret = dfs(arr, a);
	if (ret != 0) {
		return 0;
	}

	int bitCnt = 0;
	long long output = 0;
	while (1) {
		if (arr[I3P] >= 2) {
			output = output + 9 * CalcTenN(bitCnt);
			arr[I3P] = arr[I3P] - 2;
		} else if (arr[I2P] >= 3) {
			output = output + 8 * CalcTenN(bitCnt);
			arr[I2P] = arr[I2P] - 3;
		} else if (arr[I7P] >= 1) {
			output = output + 7 * CalcTenN(bitCnt);
			arr[I7P] = arr[I7P] - 1;
		} else if (arr[I3P] >= 1 && arr[I2P] >= 1) {
			output = output + 6 * CalcTenN(bitCnt);
			arr[I3P] = arr[I3P] - 1;
			arr[I2P] = arr[I2P] - 1;
		} else if (arr[I5P] >= 1) {
			output = output + 5 * CalcTenN(bitCnt);
			arr[I5P] = arr[I5P] - 1;
		} else if (arr[I2P] >= 2) {
			output = output + 4 * CalcTenN(bitCnt);
			arr[I2P] = arr[I2P] - 2;
		} else if (arr[I3P] >= 1) {
			output = output + 3 * CalcTenN(bitCnt);
			arr[I3P] = arr[I3P] - 1;
		} else if (arr[I2P] >= 1) {
			output = output + 2 * CalcTenN(bitCnt);
			arr[I2P] = arr[I2P] - 1;
		} else {
			break;
		}
		if (output > 0xFFFFFFFF/2) {
			return 0;
		}
		bitCnt++;
	}
	return output;
}
```