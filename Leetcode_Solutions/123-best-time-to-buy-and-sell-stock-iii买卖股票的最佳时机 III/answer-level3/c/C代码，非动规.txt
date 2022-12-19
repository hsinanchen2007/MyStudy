### 解题思路
一、思路：
1、首先，总共days天，最终收益大小取决于这些天内的操作；
2、其次，上述股票操作是指 买入（花钱）、卖出（赚钱）、观望（不买不卖，不变）三种；
3、再次，具体每天开盘能做什么操作，又取决于当前的入市状态status，包括持股和持币两种，持股时只能卖出和观望，持币时只能买入和观望；
4、最后，需要再考虑最多交易两次的情况（exchange）
二、方法：
看了题解里千篇一律动规，我使用了DFS+记忆，开始有些编译问题，解决后很快就过了198个用例，仅剩最后两个大数据，加了记忆后最后一个超大数据还是没过，翻了下某个同学的提示，对输入为零的情况再进行剪枝，最终顺利通过。

代码不多，情况如下：

执行用时 :12 ms, 在所有 C 提交中击败了57.50%的用户
内存消耗 :8.7 MB, 在所有 C 提交中击败了16.73%的用户

### 代码

```c
#define DO_NOTHING 0
#define BUYIN 1
#define SELLOUT 2

#define NO_TICKET 0
#define HAS_TICKET 1

int maxExchange = 2;
int aaa[81920][2][3] = {0};
int dfs(int* prices, int pricesSize, int days, int status, int Exchange){
    int mon0, mon1, mon2, monMax;

    if (pricesSize - 1 < days){
        return 0;
    }

    if (2 <= Exchange){
        return 0;
    }

    if (0 < aaa[days][status][Exchange]){
        return aaa[days][status][Exchange];
    }

    //每天只有两种状态，持有和非持有，每天三种选择，分别是0买入，1卖出和2不变，如果当前是持有，只能1/2，如果当前是非持有，只能0/2；
    switch (status){
        case HAS_TICKET:{
            mon0 = dfs(prices, pricesSize, days + 1, HAS_TICKET, Exchange);
            mon2 = dfs(prices, pricesSize, days + 1, NO_TICKET, Exchange + 1) + prices[days];          
            monMax = mon0 < mon2 ? mon2 : mon0;
            break;
        }
        case NO_TICKET:{
            mon0 = dfs(prices, pricesSize, days + 1, NO_TICKET, Exchange);
            mon1 = dfs(prices, pricesSize, days + 1, HAS_TICKET, Exchange)  - prices[days];
            monMax = mon0 < mon1 ? mon1 : mon0;
            break;
        }
        default :{
            assert(0);
            break;
        }
    }

    aaa[days][status][Exchange] = monMax;
    return monMax;
}
int maxProfit(int* prices, int pricesSize){
    int i, j, k, l;
    int myPricesSize;
    int mon;
    int monMax = 0;

    //合法性检查
    if (2 > pricesSize){
        return 0;
    }

    myPricesSize = pricesSize;
    for (i = pricesSize - 1; 0 < i; i--){
        if (0 == prices[i]){
            myPricesSize--;
        }
        else{
            break;
        }
    }

    //遍历所有点i买入亏钱，j卖出赚钱，算总收益，初始收益0
    for (i = 0; i < myPricesSize; i++){
        mon = dfs(prices, myPricesSize, i + 1, HAS_TICKET, 0) - prices[i];
        monMax = monMax < mon ? mon : monMax;
    }

    for (i = 0; i < myPricesSize; i++){
        for (j = 0; j < 2; j++){
            for (k = 0; k < 3; k++){
                aaa[i][j][k] = 0;
            }
        }
    }

    return monMax;
}
```