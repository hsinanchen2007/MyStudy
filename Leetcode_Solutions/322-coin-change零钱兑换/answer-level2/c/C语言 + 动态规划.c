
1. 当输入金额时 0 的时候， 返回 0
2. 从小到大排序（不排序可以直接查找到最小的硬币面额）
3. 当输入金额小于时， 时无法组合的，输出 -1
4. 从最小面额值开始规划， 当等于最小面额时， 1个最小硬币就可以， 返回 1
5. 后续面值，等于遍历所有最小总金额的硬币， 总额 - 硬币额后金额最小组合 + 1，遍历后最小组合数。
6. /*

int* cmp(int* a, int*b)
{
    return *(int*)a - *(int*)b;
}
int DpCoinNum(int* coins, int* dparr, int coinsSize, int tmpamount)
{
    int minnum = INT_MAX;
    int i = coinsSize - 1;
    while (i >= 0 && coins[i] > tmpamount) {
        i--;
    }

    for (int j = i; j >= 0; j--) {
        int tmp = tmpamount - coins[j];
        if (dparr[tmp] != -1) {
            if (minnum > dparr[tmp] + 1) {
                minnum = dparr[tmp] + 1;
            }
        }
    }
    if (minnum != INT_MAX) {
        return minnum;
    }
    return -1;
}
int coinChange(int* coins, int coinsSize, int amount){
    if (amount == 0) {
        return 0;
    }
    qsort(coins, coinsSize, sizeof(int), cmp);
    if (amount < coins[0]) {
        return -1;
    }
    int dparr[amount + 1];
    int i;
    dparr[0] = 0;
    for (i = 1; i < coins[0]; i++) {
        dparr[i] = -1;
    }
    for (i ; i < amount + 1; i++) {
        dparr[i] = DpCoinNum(coins, dparr, coinsSize, i);
    }
    return dparr[amount];
}