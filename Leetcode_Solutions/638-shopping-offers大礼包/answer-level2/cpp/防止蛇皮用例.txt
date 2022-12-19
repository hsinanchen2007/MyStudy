```
class Solution {
private:
    int min_pay = INT32_MAX;
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        sort(special.begin(), special.end(), [](vector<int> &a, vector<int>&b){ return a.back() > b.back();});
        buy_sigle(price, needs);
        dfs(price, special, needs, 0);
        return min_pay;
    }
    //直接买单个，防止散装比礼包便宜的蛇皮用例
    void buy_sigle(vector<int>& price, vector<int>& needs){
        int total = 0;
        for(int i = 0; i < needs.size(); ++i){
            total += price[i] * needs[i];
        }
        min_pay = min(min_pay, total);
    }
    //用单个补足大礼包的dfs
    void dfs(vector<int> &price, vector<vector<int>>& special, vector<int> still_needs, int cur_pay){
        int can_exit = 1;
        //判断物品是否恰好满足购物清单
        for(auto &i : still_needs){
            if(i != 0){
                can_exit = 0;
                break;
            }
        }
        if(can_exit){
            min_pay = min(min_pay, cur_pay);
            return;
        }
        for(auto &gift : special){
            vector<int> still_needs_tmp;
            int buy_gift = 1;
            //判断买礼包会不会超过购物清单，并且将买过的个数减去更新购物清单
            for(int i = 0; i < still_needs.size(); i++){
                if(still_needs[i] - gift[i] < 0){
                    buy_gift = 0;
                    break;
                } else{
                    still_needs_tmp.emplace_back(still_needs[i] - gift[i]);
                }
            }
            //还没买购花费都超过了已有的最优方案直接放弃
            if(min_pay < cur_pay + gift.back()){
                buy_gift = 0;
            }
            //能买礼包直接买，一般来说礼包总是便宜的，至于哪种便宜交给dfs
            if(buy_gift){
                dfs(price, special, still_needs_tmp, cur_pay + gift.back());
            } else{
            //不能买礼包就用单个补足
                int total = cur_pay;
                for(int i = 0; i < still_needs.size(); ++i){
                    total += still_needs[i] * price[i];
                }
                min_pay = min(min_pay, total);
            }
        }
    }
};
```
