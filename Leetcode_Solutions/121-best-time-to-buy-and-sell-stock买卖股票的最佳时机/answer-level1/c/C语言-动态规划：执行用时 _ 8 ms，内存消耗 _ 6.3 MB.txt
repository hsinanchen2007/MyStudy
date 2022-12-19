### 解题思路
1、计算每一天与前一天的差值，并计算差值的和，如果为负数则赔钱置0重新计算；
2、记录差值和的最大值，即为结果。

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    int i;
    int diff;
    int sum = 0;
    int result = 0;

    pricesSize--;

    for (i = 0; i < pricesSize; i++) {
        diff = prices[i + 1] - prices[i];
        sum = (sum + diff < 0) ? 0 : sum + diff;
        result = (sum > result) ? sum : result;
    }

    return result;
}
```