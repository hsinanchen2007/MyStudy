```Java
public int coinChange(int[] coins, int amount) {
    if (amount < 1) {
        return 0;
    }
    return coinChange(coins, amount, new int[amount]);
}

private int coinChange(int[] coins, int amount, int[] count) {
    if (amount < 0) {
        return -1;
    }
    if (amount == 0) {
        return 0;
    }
    if (count[amount - 1] != 0) {
        return count[amount - 1];
    }
    int min = Integer.MAX_VALUE;
    for (int coin: coins) {
        int ret = coinChange(coins, amount - coin, count);
        if (ret >= 0 && ret < min) {
            min = 1 + ret;
        }
    }
    count[amount - 1] = (min == Integer.MAX_VALUE) ? -1: min;
    return count[amount - 1];
}
```
