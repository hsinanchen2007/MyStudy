递归方法做的，贪心加剪枝。
 int coinChange(vector<int>& coins, int amount) {
         if(amount == 0) return 0;
         int m = __INT_MAX__;
       
        sort(coins.rbegin(),coins.rend());
        coinfun(coins, amount, 0, 0, m);
        if(m ==__INT_MAX__) return -1;
        return m;

    }
    void coinfun(vector<int>& coins, int amount, int index, int count, int& m)
    {
        if(amount == 0){
            m = min(m, count); 
            return;
        }
        if(index == coins.size()){
            return;
        }
        for(int k=amount/coins[index];k>=0&& count+k<m;k--){
            coinfun(coins, amount-k*coins[index], index+1, count+k, m);
        }


    }