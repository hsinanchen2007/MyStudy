```
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.size() == 0)
            return 0;
        int p_i_0 = 0, //i==-1,initialize
            p_i_1 = INT_MIN;
        for (int i:prices) {
            int temp = p_i_0;
            p_i_0 = max( p_i_0, p_i_1+i ); 
            p_i_1 = max( p_i_1, temp-i-fee );
            //交易费最好在买入的时候减去，在卖出的时候减去容易导致
            //溢出，因为p_i_1被初始化为最小int值了。
        }
        return p_i_0;
    }
};
```
