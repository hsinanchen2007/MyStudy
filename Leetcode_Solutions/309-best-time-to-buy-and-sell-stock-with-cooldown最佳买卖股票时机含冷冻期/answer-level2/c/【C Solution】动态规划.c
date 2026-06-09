### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX(x,y) (x)>(y) ? (x) : (y);

int maxProfit(int* prices, int pricesSize){
    if(pricesSize <= 0 ){
        return 0;
    }
    // int ** dp = (int**)malloc(sizeof(int*)*pricesSize);
    // for(int i = 0; i < pricesSize ; i++){
    //     dp[i] = (int*)malloc(sizeof(int)*2);
    // }
    int temp_0 = 0 , temp_1 = INT_MIN , temp_2 = 0;
    // 0 无持有 1 持有
    for(int  i = 0 ; i < pricesSize; i++){
        int tmp = temp_0;
        temp_0 = MAX(temp_0, temp_1 + prices[i]);
        temp_1 = MAX(temp_1, temp_2 - prices[i]);
        temp_2 = tmp;
    }
    return temp_0;
}
```