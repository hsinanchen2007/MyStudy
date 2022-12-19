解题思路：相邻两天的股价，如果第二天比第一天高，则用第二天减第一天求累加，然后跳到第三天重复前面的过程即可；
很暴力的解法！！！         




int maxProfit(int* prices, int pricesSize){
    if(prices == NULL || pricesSize < 2) 
        return 0;
    // printf("pricesSize=%d   ",pricesSize);
    int i=1,index=0,j;
    int max_pro=0;
    int cost=prices[0];
    for(;i<pricesSize;i++){
        if(prices[i-1]<prices[i]){
            max_pro=max_pro+prices[i]-prices[i-1];
            index++;
        }
 
    }
    // printf("index=%d",index);
    return max_pro; 
}