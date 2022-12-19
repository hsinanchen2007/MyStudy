### 解题思路
与贪心算法类似，我是用快慢指针解决的，用时击败78.78%用户，内存消耗击败97.36%用户。如果快指针指向的元素大于慢指针指向的元素，就将他们差值加到maxProfit里。

### 代码

```c
int maxProfit(int* prices, int pricesSize){
    int maxProfit = 0, j = 1;
    for(int i = 0; i < pricesSize && j < pricesSize; i++){
        if(prices[j] - prices[i] > 0){
             maxProfit += prices[j] - prices[i];
        }
        j++;
    }
    return maxProfit;
}
```