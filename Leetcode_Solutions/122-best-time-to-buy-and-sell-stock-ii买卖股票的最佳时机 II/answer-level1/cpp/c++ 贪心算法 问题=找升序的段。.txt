先上结果
![微信图片_20200304001339.png](https://pic.leetcode-cn.com/2af5c78c344ec17cdfd7fc695bf9550d6aef62c813fe06ef579ebf280f3363a2-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200304001339.png)


此题中，找最大的利润，实际是找数组中有多少升序的子段。
每找到一段，则用最大的减去最小的，则是这段的利润。
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        //整体的最大利润
        int maxp=0;
        //子段最小值的位置所在
        int min=0;
        //子段最大值的位置所在
        int max=0;
        for(int i=1;i<prices.size();i++)
        {
           if(prices[i]<prices[i-1])//如果i-1的位置的值比i大，则一个子段查找结束
            {
                maxp+=prices[max]-prices[min]; 
                min=i;
                max=i;
            }
            else//否则，最大值的位置继续往后移
                max++;
        }
        maxp+=prices[max]-prices[min]; //若最后一段升序（也有可能不升序）。
        return maxp;

    }
};
```
