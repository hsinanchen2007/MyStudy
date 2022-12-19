### 解题思路
把最高赞的思路从头到尾看了一遍，果然菜鸟就应该紧随大佬的脚步，值得一提的是，这里在max函数上面加一行static inline,效率直接翻了一倍

### 代码

```c
static inline
int max(int a,int b){
    return a>b?a:b;
}
int maxProfit(int* prices, int pricesSize){
    int dp_i10 = 0, dp_i11 = -32768;
    int dp_i20 = 0, dp_i21 = -32768;
    for (int i=0;i<pricesSize;i++) {
        dp_i20 = max(dp_i20, dp_i21 + prices[i]);
        dp_i21 = max(dp_i21, dp_i10 - prices[i]);
        dp_i10 = max(dp_i10, dp_i11 + prices[i]);
        dp_i11 = max(dp_i11, -prices[i]);
    }
    return dp_i20;
}

```