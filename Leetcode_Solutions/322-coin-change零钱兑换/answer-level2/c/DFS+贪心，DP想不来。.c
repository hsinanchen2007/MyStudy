### 解题思路
DFS+贪心，DP想不来。

### 代码

```c
int retCountCoin = 0;
int retMin = 0;
int cmpCoin(const void *a, const void *b) {
	int *ap = (int *)a;
	int *bp = (int *)b;

	return *ap - *bp;
}

void coinChange_dfs(int* coins, int amount, int pos) {
	int devNum = 0;
	int leftAmount = 0;
	int i;

	if ((pos < 0) || (coins[pos] <= 0)) {
		return;
	}
	
	devNum = amount / coins[pos];

	if ((amount % coins[pos]) == 0) {
		retCountCoin += devNum;
		if (retCountCoin < retMin) {
			retMin = retCountCoin;
		}
		retCountCoin -= devNum;
		return;
	}
	
	for (i = devNum; i >= 0; i --) {
		leftAmount = (amount - i * coins[pos]);
		retCountCoin += i;
		if (retCountCoin >= retMin) {
			retCountCoin -= i;
			return;
		}
		coinChange_dfs(coins, leftAmount, (pos - 1));
		retCountCoin -= i;
	}

	return;
}

int coinChange(int* coins, int coinsSize, int amount){
	retCountCoin = 0;
	retMin = INT_MAX;

	if ((coins == NULL) || (coinsSize == 0)) {
		return -1;
	}

	if (amount == 0) {
		return 0;
	}

	qsort(coins, coinsSize, sizeof(int), cmpCoin);
	coinChange_dfs(coins, amount, (coinsSize - 1));

	return (retMin == INT_MAX) ? -1 : retMin;
}
```