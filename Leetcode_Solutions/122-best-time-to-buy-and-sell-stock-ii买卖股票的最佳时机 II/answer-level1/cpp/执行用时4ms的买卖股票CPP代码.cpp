    

int maxProfit(vector<int>& prices) {
     if(prices.size()==0) return 0;
	 int sum=0;
	 for (decltype(prices.size()) i = 0; i !=prices.size() ; ++i) {
		  auto j=i;
		  while((j+1!=prices.size())&&prices.at(j+1)>prices.at(j))
		  	++j;
          sum+=(prices.at(j)-prices.at(i));
          i=j;
    	}
    return sum;
    }


![image.png](https://pic.leetcode-cn.com/1a9667cfe8246c02ab82f6009d332c34199fc25c6a6b34f76d5529582a511be2-image.png)
