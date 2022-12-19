
### 代码

```cpp
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        size = prices.size();
        if (2*k > size)        
            return maxProfitInfinite(prices);
        
        int profit[size][k+1][2];
        for (int i=0; i<size; i++) {
            profit[i][0][0] = 0;
            for (int j=1; j<=k; j++) {
                if (i==0) {
                    profit[i][j][0] = 0;
                    profit[i][j][1] = -prices[i];
                    continue;
                }
                profit[i][j][0] = max( profit[i-1][j][0], profit[i-1][j][1]+prices[i]);
                profit[i][j][1] = max( profit[i-1][j][1], profit[i-1][j-1][0]-prices[i]);
            }
        }

        return profit[size-1][k][0];
    }

private:
    int size;
    int maxProfitInfinite(vector<int> &p) {
    //the times of transaction is more than (size+1)/2, is same with infinite times
        int res = 0;
        for (int i=0; i<size-1; i++) {
            if (p[i]<p[i+1])
                res += p[i+1]-p[i];
        }
        return res;
    }
};
```