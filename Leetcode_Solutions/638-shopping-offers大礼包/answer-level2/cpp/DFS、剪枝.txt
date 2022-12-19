
```
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int res=INT_MAX;
        if(needs.size()==0)
            return 0;
        backtrack(price, special, needs, 0, res);
        return res;
    }
    
    void backtrack(vector<int>& price, vector<vector<int>>& special, vector<int> needs, int money, int& res)
    {
        int m=needs.size();
           
        for(int i=0; i<special.size(); i++)
        {
            int sat=1;
            for(int j=0; j<m; j++)
                if(special[i][j]>needs[j])
                    sat=0;
            if(sat){
                if(money+special[i][m]<res)
                {
                    vector<int> need(needs);
                    for(int j=0; j<m; j++)
                        need[j]-=special[i][j];
                    backtrack(price, special, need, money+special[i][m] ,res);
                }
            }
        }
        
        for(int i=0; i<price.size(); i++)
        {
            money += price[i]*needs[i];
            if(money>res)
                return;
        }
        
        res=min(res, money);
        
    }
};
```
