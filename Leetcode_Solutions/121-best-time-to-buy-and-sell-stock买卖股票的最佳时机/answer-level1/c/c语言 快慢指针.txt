#define MAX(a, b) ((a) > (b) ? (a) : (b))
int maxProfit(int* prices, int pricesSize){
    int slow = 0;
    int fast = 1;
    int ret = 0;

    if(pricesSize <= 1){
        return ret;
    }

    while(fast < pricesSize){
        if(prices[slow] > prices[fast]){
            slow = fast;
        }

        if(prices[slow] < prices[fast]){
            ret = MAX(ret, prices[fast] - prices[slow]);
        }

        fast++;
    }

    return ret;
}