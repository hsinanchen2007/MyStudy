![image.png](https://pic.leetcode-cn.com/4ac75cd1d62b6d974938bf84e4bb9240c2bdd1b4eb3e84caf49221ef734fdc72-image.png)
就第一个例子来说
假设我in买入，out卖出，lastDay = in，看看第二天亏不，
如果亏了我就不买 =>   in==out; out++; lastDat = in；并且把此次的赚的钱加入sum；在吧sumItem = 0;(很显然，第一天没赚钱)
如果没亏，记下我这波赚了多少钱  => sumItem = prices[out]-prices[in]，先不卖，因为后面可能可以赚更多。所以记下今天的日子，lastDay = out；out++；
第二天（下一次循环）判断out和昨天的价格，如果还能赚，继续赚=>sumItem = prices[out]-prices[in] 不能赚就卖了
```
public  int maxProfit(int[] prices) {
        int in = 0;
        int out = 1;
        int sum = 0;
        int lastDay = 0;
        int sumItem = 0;
        while (in <prices.length && out<prices.length){
            if (prices[lastDay]>prices[out]){
                //亏了
                in = out;
                lastDay = in;
                //重置天数
                out++;
                //下一天
                sum+=sumItem;
                //把此次的收益记下来
                sumItem=0;
                //重置此次的收益
            }else {
                //赚了
                sumItem = prices[out]-prices[in];
                //重新计算这次赚了多少钱
                lastDay = out;
                //今天就是明天的昨天
                out++;
                //下一天
                if (out==prices.length){
                    //假如明天是世界末日（明天没有东西了，投资结束了），
                    sum+=sumItem;
                    //赶紧把这次收益记下来
                }
            }

        }

        return sum;
    }
```
