**
贪心思路：总在股价上升转为下降前卖股票，在股价下降转为上升前买股票
1.设置状态变量situation=初始化为start（start，up，down）设置利润总量allprofit设置买入index_buy和卖出index_sell
2.for循环遍历数组，switch前一个状态situation 用switch和if更新状态和allprofit                     
3.循环结束后 return allprofit
```
代码块int maxProfit(vector<int>& prices) {
	const int start = 0;
	const int up = 1;
	const int down = 2;
	int situation = start;
	int allprofit = 0;
	int index_buy = 0;
	int index_sell = 0;
	for (int i = 1; i < prices.size(); i++)
	{
		switch (situation){
		case start:{
			if (prices[i] >= prices[i - 1])
			{
				situation = up;
				index_buy = 0;
			}
			else
			{
				situation = down;
			}
			
			break;
		           }
		
			
		
		case up:{
			if (prices[i] < prices[i - 1])
			{
				situation = down;
				index_sell = i - 1;
				allprofit += prices[index_sell] - prices[index_buy];
			}
			else
			{

				
				situation = up;
			}
			
			break;
		       }
			
		
		case down:{
			if (prices[i] >= prices[i - 1])
			{
				situation = up;
				index_buy = i - 1;
			}
			else
			{


				situation = down;

			}
			break;
			
		    }

		

		


		}
	}
	if (index_buy >= index_sell && index_buy < prices.size() - 1&&situation==up)
		allprofit += prices[prices.size() - 1] - prices[index_buy];
	
	
	return allprofit;

}
```
