```C++
// 因为挑选石头是任意的, 不能使用贪心法每次挑选重量最大的两块石头
// 第一次挑选a,b, 放回a-b, ....., 第n次挑选c,a-b, 放回c-a+b， 最终结果为(a+d+c+g)-(b+e+f)
// 因此, 可以视作一个0-1背包问题，将石头分为两堆，两堆重量之差最小是多少
// 背包容量为 sum/2， 每个石头拿起来或者不拿起来，能装下最多的石头重量是多少
int lastStoneWeightII(vector<int> &stones){
    int sum = accumulate(stones.begin(), stones.end(), 0);
    vector<bool> dp(sum / 2 + 1, false);    // dp[i] - 是否可以找到一部分石头，其总重量为i
    dp[0] = true;                           // dp[0] - 不拿石头时，其总重量为0
    
    for(int i = 0; i < stones.size(); ++i)
        for(int w = dp.size() - 1; w >= stones[i]; --w)
            dp[w] = dp[w] | dp[w - stones[i]];
    
    // 找到可以放的最大重量假设为i, 则两部分的差值为 (sum - i) - i
    for(int i = dp.size() - 1; i >= 0; --i)
        if(dp[i] == true)
            return sum - 2 * i;
    
    return sum;
}
```
