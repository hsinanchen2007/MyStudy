### 解题思路
![微信图片_20200314184607.png](https://pic.leetcode-cn.com/b7aff3ecaca44669130f4f2b53845abc442c5c6f1223100d0e670ea2b94e6f7b-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200314184607.png)
首先本题其实很简单，就相当于你有了上帝视角，提前知道明天的股价。
然后每一天都和后一天的股价相比较，若小于后一天就在当天买入，否则，进入下一天。
如果最后一天前有买入，就要卖出。
### 代码

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1)//当数组为空或者只有第一天交易时，利润为0
		return 0;
		int result = 0;
		int temp=prices[0];
	
		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i] < prices[i-1])
			{
				result += prices[i - 1] - temp;
				temp = prices[i];
			}	
		}
		if (temp != prices[prices.size() - 1])//！！如果最后一天前有买入，就要卖出。
			result += prices[prices.size() - 1] - temp;
		return result;
	}
};
```